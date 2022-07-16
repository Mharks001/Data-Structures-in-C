#include "../header files/Binary_Tree_Traversal.h"

//	Level Order Iterative: Level by Level
void LevelOrder(Btree B, void (*func)(Btree))
{
	if (B == NULL)	return;

	queue q = CreateQueue();
	
	EnQueue(&q, B);
	while (Front(q, &B))
	{
		DeQueue(&q);
		func(B);
		if (B->left)EnQueue(&q, B->left);
		if (B->right)EnQueue(&q, B->right);
	}
}

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++

//	InOrder Recursive: Left -> Data -> Right
void inorder(Btree B, void (*func)(Btree))
{
	if (B == NULL)	return;

	inorder(B->left, *func);
	func(B);
	inorder(B->right, *func);
}

// InOrder Iterative: Left -> Data -> Right
void inorder_Iter(Btree B, void (*func)(Btree))
{
	if (B == NULL)	return;
	queue q = CreateQueue();
	
	EnQueue(&q, B);
	while (Front(q, &B))
	{
		DeQueue(&q);
		
		func(B);

		if(B->left != NULL)		EnQueue(&q, B->left);
		if(B->right != NULL)	EnQueue(&q, B->right);
	}
}

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++

//	PreOrder Recursive: Data -> Left -> Right
void preorder(Btree B, void (*func)(Btree))
{
	if (B == NULL)	return;

	func(B);
	preorder(B->left, func);
	preorder(B->right, func);
}

//	PreOrder Iterative: Data -> Left -> Right
void preoder_Iter(Btree B, void (*func)(Btree))
{
	if (B == NULL)	return;
	
	int proceed = 1;
	stack s = CreateStack();

	while (proceed)
	{
		while (B != NULL){
			func(B);
			Push(&s, B);
			B = B->left;
		}
		do{
			if (!Top(s, &B))	return;
			Pop(&s);
			B = B->right;
		}while(B == NULL);
	}
}

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++

//	PostOrder Recursive: Left -> Right -> Data
void postorder(Btree B, void (*func)(Btree))
{
	if (B == NULL)	return;

	postorder(B->left, func);
	postorder(B->right, func);
	func(B);
}

//	PostOrder Iterative: Left -> Right -> Data
void postoder_Iter(Btree B, void (*func)(Btree))
{
	if (B == NULL)	return;

	
	int proceed = 1;
	Btree prev = NULL;
	stack s = CreateStack();

	while (proceed)
	{
		while (B != NULL)
		{
			Push(&s, B);
			B = B->left;
		}
		do {
			
			if (!Top(s, &B))	return;
			if (B->right == NULL || prev == B->right)
			{
				func(B);
				Pop(&s);
				prev = B;
				B = NULL;
			}
			else B = B->right;

		} while (B == NULL);
	}
}