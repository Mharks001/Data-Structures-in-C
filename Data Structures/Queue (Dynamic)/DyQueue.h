#include <stdio.h>
#include <stdlib.h>
#include "Queue_Type.h"

typedef struct node{
	Qucase data;
	struct node* next;
}node;

typedef struct queue {
	node* front;
	node* rear;
}queue;

queue CreateQueue(void);
int isEmptyQueue(queue q);
int isFullQueue(queue q);
int EnQueue(queue* q, Qucase e);
int DeQueue(queue* q);
int Front(queue q, Qucase* e);