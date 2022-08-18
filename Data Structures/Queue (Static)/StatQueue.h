#include "Queue_Type.h"
#define STD_QUEUE_SIZE 50

typedef struct queue {
	Qucase data[STD_QUEUE_SIZE];
	int front;
	int rear;
}queue;

queue CreateQueue(void);
int isEmptyQueue(queue q);
int isFullQueue(queue q);
int EnQueue(queue* q, Qucase e);
int DeQueue(queue* q);
int Front(queue q, Qucase* e);