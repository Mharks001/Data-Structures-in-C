#include <stdio.h>
#include <stdlib.h>
#include "Binary_Tree_Type.h"

typedef struct BTnode {
	Btcase data;
	struct BTnode* left;
	struct BTnode* right;
}*Btree;

Btree Construct(Btcase data, Btree left_subtree, Btree right_subtree);
void Deconstruct(Btree Binary_Tree);