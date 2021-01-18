CC=gcc
OBJS=main.o 
OBJS+=tool1.o tool2.o
CFLAGS=-g -Wall -D_FILE_OFFSET_BITS=64
LDFLAGS=-lm


mytool:$(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)


%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@


clean:
	$(RM) -rf *.o mytool 	




