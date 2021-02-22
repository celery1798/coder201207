#ifndef _PROTO_H__
#define _PROTO_H__

#define KEYPATH		"/etc/hosts"
#define KEYPROJ		'a'


#define PATHMAX		1024
#define DATAMAX		1024

enum
{
	MSG_PATH=1,
	MSG_S2C
};

struct msg_path_st
{
	long mtype;			/*must be MSG_PATH*/
	char path[PATHMAX];		/*ASCIIZ带尾0的串*/
};

struct msg_s2c_st
{
	long mtype;			/*must be MSG_S2C*/
	char data[DATAMAX];
	int datalen;
	/*
	datalen > 0:	data
			= 0:	EOF
			< 0:	-error	
	*/
};
/*
struct msg_s2c_st rbuf;
msgrcv(msgid,&rbuf,....)
if(rbuf.datalen < 0)
	.....
*/
#endif


