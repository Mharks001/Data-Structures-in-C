#include "Max_Heap.h"

static void swap(int* A, int* B) { int tmp = *A; *A = *B; *B = tmp; }

static void insert(heap H, int data) 
{
    if (H == NULL)   return;

    int count = H->count;
    if (count == H->capacity) Resize_Heap(H);

    *(H->array + count) = data, H->count++;

    Percolate_Up(H, count);
}

static int isMaxHeap_Helper(heap H, int index)
{
    int left = Left_Child(index);
    int right = Right_Child(index);

    int max = *(H->array + index);

    if (left < H->count)
    {
        if (!isMaxHeap_Helper(H, left))     return 0;
        if (max < *(H->array + left))       return 0;
    }
    else return 1;

    if (right < H->count)
    {
        if (!isMaxHeap_Helper(H, right))    return 0;
        if (max < *(H->array + right))      return 0;
    }

    return 1;
}
extern int isMaxHeap(heap H)
{
    if (H == NULL)   return 0;
    if (H->array == NULL || H->count == 0)   return 0;
    return isMaxHeap_Helper(H, 0);
}

void Build_Heap(heap H, int* array, int size)
{
    if (array == NULL || size == 0) 
    {
        H->array = NULL;
        H->capacity = H->count = 0;
        return;
    }
    
    if (H->array != NULL)   free(H->array);

    H->capacity = size;
    H->count = 0;

    H->array = (int*)malloc(sizeof(int)*size);
    if (H->array == NULL) { H->capacity = 0; return; }

    for(int i = 0; i < size; i++)
        insert(H, *(array + i));
}

int GetMaximum_Heap(heap H, int* e)
{
    if (e == NULL || H == NULL || H->array == NULL || H->count == 0)    return 0;
    *e = *(H->array);
    return 1;
}
int DeleteMaximum_Heap(heap H)
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
    if(index <= 0 || index >= H->count)   return;
    
    int parent_index = Parent(index);

    if (parent_index < 0 || *(H->array + index) <= *(H->array + parent_index))   return;

    swap(H->array + index, H->array + parent_index);
    Percolate_Up(H, parent_index);
}
void Percolate_Down(heap H, int index)
{
    if(index < 0 || index >= H->count)   return;
    
    int child_index = Left_Child(index);
    int max = index;
    
    if(child_index < H->count && *(H->array + max) < *(H->array + child_index))   max = child_index;
    child_index++;
    if(child_index < H->count && *(H->array + max) < *(H->array + child_index))   max = child_index;
    
    if(max == index)   return;
    
    swap(H->array + index, H->array + max);
    Percolate_Down(H, max);
}

int Heapify(int* array, int size)
{
    if(array == NULL || size <= 1)  return 1;
    int index = Parent(size - 1);
    
    heap H = Create_Heap();
    if (H == NULL)   return 0;
    if (H->array)    free(H->array);
    
    H->array = array;
    H->capacity = H->count = size;

    if(H == NULL)   return 0;

    while(index >= 0)   Percolate_Down(H, index), index--;
    free(H);

    return 1;
}