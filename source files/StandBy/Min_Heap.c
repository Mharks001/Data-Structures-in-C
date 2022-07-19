#include "Min_Heap.h"

static void swap(int* A, int* B) { int tmp = *A; *A = *B; *B = tmp; }
static void insert(heap H, int data)
{
    int count = H->count;
    if (count == H->capacity) Resize_Heap(H);

    *(H->array + count) = data, H->count++;
    Percolate_Up(H, count);
}

static int isMinHeap_Helper(heap H, int index)
{
    int left = Left_Child(index);
    int right = Right_Child(index);

    if (left < H->count)
    {
        if (!isMinHeap_Helper(H, left))    return 0;
        if(*(H->array + index) > *(H->array + left))    return 0;
    }
    else return 1;
    if (right < H->count)
    {
        if (!isMinHeap_Helper(H, right))    return 0;
        if (*(H->array + index) > *(H->array + right))  return 0;
    }
    return 1;
}
extern int isMinHeap(heap H)
{
    if (H == NULL || H->array == NULL || H->count == 0)    return 0;
    return isMinHeap_Helper(H, 0);
}

void Build_Heap(heap H, int* array, int size)
{
    if (array == NULL || size == 0)  return NULL;
    
    H->array = (int*)malloc(sizeof(int) * size);
    if (H->array == NULL)   return;
    
    H->count = 0;
    H->capacity = size;

    for (int i = 0; i < size; i++) insert(H, *(array + i));
}

int GetMinimum_Heap(heap H, int* e)
{
    if (e == NULL || H == NULL || H->array == NULL || H->count == 0)    return 0;
    *e = *(H->array);
    return 1;
}
int DeleteMinimum_Heap(heap H)
{
    if (H == NULL)   return 0;

    int* array = H->array;
    if (array == NULL || H->count <= 0)  return 0;

    H->count--;
    if (H->count == 0)   return 1;

    *(array) = *(array + H->count);

    Percolate_Down(H, 0);
    return 1;
}


void Percolate_Up(heap H, int index)
{
    if (index <= 0 || index > H->count)   return;

    int parent_index = Parent(index);

    if (parent_index < 0 || *(H->array + index) >= *(H->array + parent_index))   return;

    swap(H->array + index, H->array + parent_index);
    Percolate_Up(H, parent_index);
}
void Percolate_Down(heap H, int index)
{
    if (index < 0 || index > H->count)   return;

    int child_index = Left_Child(index);
    int min = index;

    if (child_index < H->count && *(H->array + min) > *(H->array + child_index))   min = child_index;
    child_index++;
    if (child_index < H->count && *(H->array + min) > *(H->array + child_index))   min = child_index;
    if (min == index)   return;

    swap(H->array + index, H->array + min);
    Percolate_Down(H, min);
}

int Heapify(int* array, int size)
{
    if (array == NULL || size <= 1)  return 1;
    int index = Parent(size - 1);

    heap H = Create_Heap();
    if (H == NULL)   return 0;

    if (H->array)    free(H->array);

    H->array = array;
    H->count = H->capacity = size;

    while (index >= 0)   Percolate_Down(H, index), index--;

    free(H);

    return 1;
}