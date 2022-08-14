#include "DataType headers/Stack_Type.h"
#define STD_STACK_SIZE 50

typedef struct stack {
	Stcase data[STD_STACK_SIZE];
	int top;
}stack;

stack CreateStack(void);
int Push(stack* wellRef, Stcase data);
int Pop(stack* wellRef);
int Top(stack well, Stcase* data);
int isEmptyStack(stack well);
int isFullStack(stack well);