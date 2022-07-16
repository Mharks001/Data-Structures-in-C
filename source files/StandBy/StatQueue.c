#include "../header files/StatQueue.h"

queue CreateQueue(void)
{
	queue q;
	q.front = 0;
	q.rear = -1;
	return q;
}

int isEmptyQueue(queue q)
{
	return q.front == q.rear - 1;
}

int isFullQueue(queue q)
{
	return q.front == q.rear;
}

int EnQueue(queue* q, element e)
{
	if (isFullQueue(*q))	return 0;
	
	q->rear++;
	q->rear %= N;

	q->data[q->rear] = e;
	return 1;
}

int DeQueue(queue* q)
{
	if (isEmptyQueue(*q))	return 0;
	
	q->front++;
	q->front %= N;

	return 1;
}

int Front(queue q, element* e)
{
	if (isEmptyQueue(q))	return 0;
	*e = q.data[q.front];
	return 1;
}