#include "../header files/StatStack.h"

stack statCreateStack()
{
	stack well;
	well.top = -1;
	return well;
}

int statPush(stack* wellRef, Stcase data)
{
	if (statisFullStack(*wellRef)) { return 0; }
	wellRef->data[++wellRef->top] = data;
	return 1;
}

int statPop(stack* wellRef)
{
	if (statisEmptyStack(*wellRef)) { return 0; }
	wellRef->top--;
	return 1;
}

int statTop(stack well, Stcase* data) 
{
	if (statisEmptyStack(well)) { return 0; }
	*data = well.data[well.top];
	return 1;
}

int statisEmptyStack(stack well) { return well.top == -1; }
int statisFullStack(stack well) { return well.top + 1 == N; }
