#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <glob.h>
#include <string.h>

#define DELIMS		" \t\n"

struct cmd_st
{
	glob_t globres;
//	int flag1;
//	....
};


void prompt()
{
	printf("myshell-0.1:$ ");
}

int parse(char *line,struct cmd_st *res)
{
	char *tok;
	int i = 0;
	//line-> "ls -l /etc  .  -i  /tmp  -a"
			//"ls" "-l" "/etc"... 

	while(1)
	{
		tok = strsep(&line,DELIMS);
		if(tok == NULL)
			break;
		if(tok[0] == '\0')
			continue;
	
	//res->gl_pathv[];
	
		glob(tok,GLOB_NOCHECK|GLOB_APPEND*i,NULL,&res->globres);
		/*if error*/
		i = 1;
	}	
}

void parse_free(struct cmd_st *res)
{
	globfree(&res->globres);



}

int main()
{
	char *line = NULL;
	size_t linesize = 0;
	pid_t pid;
	struct cmd_st cmd;

	while(1)
	{
		prompt();

		if(getline(&line,&linesize,stdin) < 0)
		{
			break;
		}
		//line-> "ls -l /etc  .  -i  /tmp  -a"
				//"ls" "-l" "/etc"...  -> argv 

		parse(line,&cmd);

		if(0)//内部命令
		{

		}
		else
		{
			fflush(NULL);			/*!!!*/

			pid = fork();
			if(pid < 0)
			{
				perror("fork()");
				break;
			}
			if(pid == 0)
			{
				execvp(cmd.globres.gl_pathv[0],cmd.globres.gl_pathv);
				perror("execvp()");
				exit(1);
			}
			else
				wait(NULL);
		}
	}	
	
	parse_free(&cmd);

	exit(0);

}





