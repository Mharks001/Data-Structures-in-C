#include "DyQueue.h"

queue CreateQueue(void)
{
	queue q;
	q.front = NULL;
	q.rear = NULL;
	return q;
}

int isEmptyQueue(queue q)
{
	if (q.front == NULL)	return 1;
	return 0;
}

int isFullQueue(queue q)	{return 0;}

int EnQueue(queue* q, Qucase e)
{
	node** currentRef;

	if (isEmptyQueue(*q)) currentRef = &q->front;
	else currentRef = &q->rear->next;

	(*currentRef) = (node*)malloc(sizeof(node));
	if (*currentRef == NULL)	return 0;

	(*currentRef)->data = e;
	(*currentRef)->next = NULL;
	
	q->rear = (*currentRef);

	return 1;
}

int DeQueue(queue* q)
{
	if (isEmptyQueue(*q))	return 0;
	node* tmp = q->front;
	q->front = tmp->next;
	free(tmp);
	
	return 1;
}

int Front(queue q, Qucase* e)
{
	if (isEmptyQueue(q))	return 0;

	*e = q.front->data;

	return 1;
}