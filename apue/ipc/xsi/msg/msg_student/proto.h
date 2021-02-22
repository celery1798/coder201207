#ifndef _PROTO_H__
#define _PROTO_H__

#define KEYPATH		"/etc/hosts"
#define KEYPROJ		'a'

#define MSGT		1

#define NAMESIZE	32

struct msg_st
{
	long mtype;
	int id;
	char name[NAMESIZE];
	int math;
};


#endif


