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

typedef struct msg_path_st
{
	long mtype;			/*must be MSG_PATH*/
	char path[PATHMAX];		/*ASCIIZ带尾0的串*/
}msg_path_t;

typedef struct msg_data_st
{
	long mtype;			/*must be MSG_DATA*/
	char data[DATAMAX];
	int datalen;
}msg_data_t;

typedef struct msg_err_st
{
	long mtype;			/*must be MSG_ERR*/
	int eerror;
}msg_err_t;

typedef struct msg_eot_st
{
	long mtype;			/*must be MSG_EOT*/
}msg_eot_t;


union msg_s2c_un
{
	long mtype;
	msg_data_t datamsg;
	msg_err_t errmsg;
	msg_eot_t eotmsg;
};


/*
S:
	union msg_s2c_un sbuf;
	sbuf.errmsg.mtype = MSG_ERR;
	sbuf.errmsg.eerror = errno;

	msgsnd(msgid,&sbuf,sizeof(sbuf)-sizeof(long),0);

C:
   union msg_s2c_un rbuf;
   msgrcv(msgid,&rbuf, ....)
   	
	switch(rbuf.mtype)
	{
		case MSG_DATA:
			...
			break;
		case MSG_ERR:
			...
			break;
	}
   	
 */





#endif


