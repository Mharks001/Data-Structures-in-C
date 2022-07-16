#include "../header files/Binary_Trees.h"

Btree Construct(Btcase data, Btree left, Btree right)
{
	Btree B = (Btree)malloc(sizeof(struct BTnode));
	if(B == NULL)	return NULL;
	
	B->data = data;
	B->left = left;
	B->right = right;

	return B;
}

void Deconstruct(Btree B)
{
	if(B == NULL)	return;
	
	Deconstruct(B->right);
	Deconstruct(B->left);
	free(B);
}