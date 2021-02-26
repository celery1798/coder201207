#ifndef _PROTO_H__
#define _PROTO_H__

#define DEFAULT_RCVPORT		"1989"
#define DEFAULT_MGROUP		"224.2.2.2"


#define NR_CHN		200
#define MINCHNID	1
#define MAXCHNID	(MINCHNID+NR_CHN-1)


#define CHNID_LIST	0



//每个频道的包
typedef uint8_t chnid_t;

#define MAX_MSG		(65536-20-8)
#define MAX_DATA	(MAX_MSG-sizeof(chnid_t))	

struct msg_channel_st
{
	chnid_t chnid;		// [1,200]
	uint8_t data[1];
}__attribute__((packed));


//节目单包

struct list_entry_st
{
	chnid_t chnid;      // [1,200]
	uint8_t dest[1];	//uint8_t desc[64];
}__attribute__((packed));


struct msg_list_st
{
	chnid_t chnid;		// must be CHNID_LIST
	struct list_entry_st entry[1];	
}__attribute__((packed));





#endif






