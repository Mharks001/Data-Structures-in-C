#include "DyStack.h"

stack CreateStack()
{return NULL;}

int Push(stack* wellRef, Stcase data)
{
	stack aux = (stack)malloc(sizeof(struct cell));
	if (aux == NULL) { return 0; }

	aux->data = data;
	aux->next = (*wellRef);

	(*wellRef) = aux;

	return 1;
}

int Pop(stack* wellRef)
{
	if (isEmptyStack(*wellRef)) { return 0; }
	stack tmp = *wellRef;
	*wellRef = (*wellRef)->next;
	free(tmp);
	return 1;
}

int Top(stack well, Stcase* data)
{
	if (isEmptyStack(well) || data == NULL) { return 0; }
	
	*data = well->data;
	return 1;
} 

int isEmptyStack(stack well) { return well == NULL; }