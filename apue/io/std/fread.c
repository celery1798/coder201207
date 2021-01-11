


fread(buf,40,3,fp);
-> 3

char buf[BUFSIZE];  1024

fread(buf,1,BUFSIZE,fp);				*
1 -> 1024
2 -> 10

fread(buf,BUFSIZE,1,fp);
1 -> 1
2 -> 0
