#ifndef _MEDIALIB_H__
#define _MEDIALIB_H__


struct mlib_chn_st
{
	chnid_t chnid;
	char *desc;
};

int mlib_getchnlist(struct mlib_chn_st **,int *);


int mlib_readchn(chnid, void *buf, int);



#endif




