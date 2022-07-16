#include "DataType headers/Queue_Type.h"
#define STD_QUEUE_SIZE 50

typedef struct queue {
	element data[N];
	int front;
	int rear;
}queue;

queue CreateQueue(void);
int isEmptyQueue(queue q);
int isFullQueue(queue q);
int EnQueue(queue* q, element e);
int DeQueue(queue* q);
int Front(queue q, element* e);