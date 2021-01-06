

#define QUEUEMAX	5

typedef struct
{
	int data[QUEUEMAX];
	int front;
	int tail;
}QUEUE;


QUEUE *queue_create();

int queue_isempty(QUEUE *);
int queue_isfull(QUEUE *);

int queue_en(QUEUE *,int);
int queue_de(QUEUE *,int *);

void queue_show(QUEUE *);

void queue_destroy(QUEUE *);

