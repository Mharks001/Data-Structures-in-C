#include <stdio.h>
#include <stdlib.h>
#include "DataType headers/Stack_Type.h"


typedef struct cell{
	Stcase data;
	struct cell* next;
}*stack;

stack CreateStack(void);
int Push(stack *wellRef, Stcase data);
int Pop(stack *wellRef);
int Top(stack well, Stcase *data);
int isEmptyStack(stack well);