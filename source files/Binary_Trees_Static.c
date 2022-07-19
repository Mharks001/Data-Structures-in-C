#include "Binary_Trees_Static.h"

int Create_Btree(Btree* B)
{
	B->root_index = 0;
	for(int i=1; i < N; i++)
		B->data[i].left_subtree = -1;
}


int add_left_child(Btree* B, element parent, element left_child)
{
	int i;
	int j;
	//First we need to find if the parrent node exists
	//we stop if we find the parent
	for(i=1; i < N && (B->data[i].root != parent || B->data[i].left_subtree == -1); i++);
	
	//Stopping condition
	//B->data[i].root == parent && B->data[i].left_subtree == -1
	if(i == N) //parent doesnt exist
		return 0;
		
	if(B->data[i].left_subtree != 0) //parent already has a left subtree
		return 0;
	
	//otherwise i is the index of the parent node
	
	//Now we check if the child node already exists
	for(j=1; j<N && (B->data[j].root != left_child || B->data[j].left_subtree == -1));
	
	//Stopping condition:
	//B->data[j].root == left_child && B->data[j].left_subtree != -1
	if(j<N) //left child exists
		return 0;
	
	//Finding an empty node
	for(j=1; j<N && B->data[j].left_sutree == -1; j++);
	
	if(j == N) //no empty nodes left
		return 0;
	
	//Otherwise we found an empty node
	B->data[j].root = left_child;
	B->data[j].left_subtree = 0;
	B->data[j].right_subtree = 0;
	B->data[i].left_subtree  = j;
	
	return 1;
}

int add_right_child(Btree* B, element parent, element right_child)
{
	int i;
	int j;
	//First we need to find if the parrent node exists
	//we stop if we find the parent
	for(i=1; i < N && (B->data[i].root != parent || B->data[i].right_subtree == -1); i++);
	
	//Stopping condition
	//B->data[i].root == parent && B->data[i].right_subtree == -1

	if(i == N) //parent doesnt exist
		return 0;
		
	if(B->data[i].right_subtree != 0) //parent already has a right subtree
		return 0;
	
	//otherwise i is the index of the parent node
	
	//Now we check if the child node already exists
	for(j=1; j<N && (B->data[j].root != right_child || B->data[j].right_subtree == -1));
	
	//Stopping condition:
	//B->data[j].root == right_child && B->data[j].right_subtree != -1
	if(j<N) //right child exists
		return 0;
	
	//Finding an empty node
	for(j=1; j<N && B->data[j].right_sutree == -1; j++);
	
	if(j == N) //no empty nodes left
		return 0;
	
	//Otherwise we found an empty node
	B->data[j].root = right_child;
	B->data[j].left_subtree = 0;
	B->data[j].right_subtree = 0;
	B->data[i].right_subtree  = j;
	
	return 1;
}