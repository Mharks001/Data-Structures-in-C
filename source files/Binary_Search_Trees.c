#include "Binary_Search_Trees.h"

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++

Btree maxBST(Btree B)
{
	if (B == NULL)	return NULL;
	if (B->right)	return maxBST(B->right);
	return B;
}
Btree maxBST_Iter(Btree B)
{
	if (B == NULL)	return NULL;
	while (B->right)	B = B->right;
	return B;
}

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++

Btree minBST(Btree B)
{
	if (B == NULL)	return NULL;
	if (B->left)	return minBST(B->left);
	return B;
}
Btree minBST_Iter(Btree B)
{
	if (B == NULL)	return NULL;
	while (B->left)	B = B->left;
	return B;
}

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++

int insertBST(Btree* B, Btcase e)
{
	if (B == NULL)	return 0;

	if (*B == NULL)
	{
		*B = (Btree)malloc(sizeof(struct BTnode));
		if (*B == NULL)	return 0;

		(*B)->data = e;
		(*B)->left = NULL;
		(*B)->right = NULL;

		return 1;
	}

	if ((*B)->data > e)	return insertBST(&(*B)->left, e);
	if ((*B)->data < e)	return insertBST(&(*B)->right, e);

	return 0;
}

int insertBST_Iter(Btree* B, Btcase e)
{
	if (B == NULL)	return 0;
	Btcase aux;
	while (*B != NULL)
	{
		aux = (*B)->data;
		if (aux > e) { B = &(*B)->left; continue; }
		if (aux < e) { B = &(*B)->right; continue; }
		return 0;
	}

	*B = (Btree)malloc(sizeof(struct BTnode));
	if (*B == NULL)	return 0;

	(*B)->data = e;
	(*B)->left = NULL;
	(*B)->right = NULL;

	return 1;
}

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++

int deleteBST(Btree* B, Btcase e)
{
	if (B == NULL || *B == NULL)	return 0;
	Btcase aux = (*B)->data;

	if (aux < e)	return deleteBST(&(*B)->right, e);
	if (aux > e)	return deleteBST(&(*B)->left, e);

	Btree tmp = *B;

	if ((*B)->left && (*B)->right)
	{
		tmp = maxBST((*B)->left);
		(*B)->data = tmp->data;

		return deleteBST(&(*B)->left, tmp->data);
	}

	if ((*B)->left)	*B = (*B)->left;
	else *B = (*B)->right;

	free(tmp);

	return 1;
}

int deleteBST_Iter(Btree* B, Btcase e)
{
	if (B == NULL || *B == NULL)	return 0;
	Btcase aux;
	Btree tmp;
	while (*B != NULL)
	{
		aux = (*B)->data;

		if (aux < e) { B = &(*B)->right; continue; }
		if (aux > e) { B = &(*B)->left; continue; }

		if ((*B)->right && (*B)->left)
		{
			tmp = maxBST((*B)->left);
			(*B)->data = tmp->data;

			e = tmp->data;
			B = &(*B)->left;
			continue;
		}

		tmp = *B;

		if ((*B)->left)	*B = (*B)->left;
		else *B = (*B)->right;

		free(tmp);

		return 1;
	}

	return 0;
}

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++

Btree scanBST(void)
{
	printf("\
Enter the number of node you want to insert in the Binary Search Tree with their corresponding values.\
Example:\
\
4	1 2 3 4\
");

	Btree B = NULL;
	Btcase data;
	int Node_Count;
	
	if (scanf("%i", &Node_Count) != 1) return NULL;
		
	for (int i = 0; i < Node_Count; i++){
		
		if (scanf("%i", &data) != 1)	return NULL;
		insertBST(&B, data);
	}
	
	return B;
}
