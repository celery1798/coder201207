#ifndef _PROTO_H__
#define _PROTO_H__

	
#define RCVPORT		"1999"


#define NAMESIZE	32

struct msg_st
{
	uint32_t id;
	uint8_t name[NAMESIZE];
	uint32_t math;
}__attribute__((packed));


#endif


