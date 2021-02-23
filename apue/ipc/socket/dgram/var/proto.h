#ifndef _PROTO_H__
#define _PROTO_H__

	
#define RCVPORT		"1999"


#define NAMEMAX	(512-8-8)

struct msg_st
{
	uint32_t id;
	uint32_t math;
	uint8_t name[1];
}__attribute__((packed));


#endif


