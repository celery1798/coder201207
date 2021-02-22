#ifndef _PROTO_H__
#define _PROTO_H__

#define KEYPATH		"/etc/hosts"
#define KEYPROJ		'a'


#define PATHMAX		1024
#define DATAMAX		1024

enum
{
	MSG_PATH=1,
	MSG_DATA,
	MSG_ERR,
	MSG_EOT
};

struct msg_path_st
{
	long mtype;			/*must be MSG_PATH*/
	char path[PATHMAX];		/*ASCIIZ带尾0的串*/
};

struct msg_data_st
{
	long mtype;			/*must be MSG_DATA*/
	char data[DATAMAX];
	int datalen;
};

struct msg_err_st
{
	long mtype;			/*must be MSG_ERR*/
	int eerror;
};

struct msg_eot_st
{
	long mtype;			/*must be MSG_EOT*/
};




#endif


