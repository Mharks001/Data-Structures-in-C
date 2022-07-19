#include "Heap.h"

int Parent(int child_index) { return (child_index - 1) / 2; }
int Left_Child(int parent_index) { return 2 * parent_index + 1; }
int Right_Child(int parent_index) { return 2 * parent_index + 2; }


heap Create_Heap()
{
    heap H = (heap)malloc(sizeof(struct heap));
    if (H == NULL)   return NULL;

    H->array = (int*)malloc(sizeof(int*)*DEFAULT_HEAP_CAPACITY);
    H->capacity = DEFAULT_HEAP_CAPACITY;
    H->count = 0;

    return H;
}

int Resize_Heap(heap H)
{
    if (H == NULL) return 0;

    int* second = (int*)malloc(sizeof(int) * 2 * H->capacity);
    if (second == NULL)  return 0;

    int* aux = H->array;
    int index = 0, size = H->count;
    while (index < size) *(second + index) = *(aux + index), index++;

    free(H->array);
    H->array = second;

    return 1;
}

int Destroy_Heap(heap* H)
{
    if (H == NULL)  return 0;
    if (*H == NULL) return 1;

    if ((*H)->array != NULL)    free((*H)->array);
    
    
    *H = NULL;
    
    return 1;
}