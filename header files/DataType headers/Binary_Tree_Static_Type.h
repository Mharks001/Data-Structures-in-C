typedef int element;

typedef struct
{
	element root;
	int left_subtree; //represents indices
	int right_subtree;
}node;

typedef struct
{
	node data[N];
	int root_index;
} Btree;