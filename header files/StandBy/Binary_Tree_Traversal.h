#include "Binary_Trees.h"
#include "DyQueue.h"
#include "DyStack.h"

void	LevelOrder		(Btree B, void (*func)(Btree));

void	inorder			(Btree B, void (*func)(Btree));
void	preorder		(Btree B, void (*func)(Btree));
void	postorder		(Btree B, void (*func)(Btree));

void	inorder_Iter	(Btree B, void (*func)(Btree));
void	preoder_Iter	(Btree B, void (*func)(Btree));
void	postoder_Iter	(Btree B, void (*func)(Btree));