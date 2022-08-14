#include <stdio.h>
#include <stdlib.h>


#define DEFAULT_HEAP_CAPACITY 32

typedef struct heap {
    int* array;
    int count;
    int capacity;
}*heap;

int Parent(int child_index);
int Right_Child(int parent_index);
int Left_Child(int parent_index);

heap Create_Heap();
int Resize_Heap(heap H);
int Destroy_Heap(heap* H);