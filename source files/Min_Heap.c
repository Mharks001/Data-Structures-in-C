#include "../header files/Min_Heap.h"

static void swap(int* A, int* B) { int tmp = *A; *A = *B; *B = tmp; }

static void fill(heap H, int index, int data) { *(H->array + index) = data; Precolate_Down(H, index); Precolate_Up(H, index); }
static void value(heap H, int index) { if (index > H->count) return;   return *(H->array + index); }
static void insert(heap H, int data) { if (H->count == H->capacity) Resize_Heap(H);   fill(H, H->count++, data); }


heap Build_Heap(int* array, int size)
{
    if (array == NULL || size == 0)  return NULL;

    heap H = (heap)malloc(sizeof(struct heap));
    if (H == NULL)   return NULL;

    H->capacity = DEFAULT_HEAP_CAPACITY;
    H->count = 0;

    H->array = (int*)malloc(sizeof(int) * DEFAULT_HEAP_CAPACITY);
    if (H->array == NULL) { free(H); return NULL; }

    for (int i = 0; i < size; i++) insert(H, *(array + i));

    return H;
}

void Percolate_Up(heap H, int index)
{
    if (index <= 0 || index > H->count)   return;

    int parent_index = Parent(index);

    if (parent_index < 0 && *(H->array + index) >= *(H->array + parent_index))   return;

    swap(H->array + index, H->array + parent_index);
    Precolate_Up(H, parent_index);
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
    Precolate_Down(H, min);
}

int Heapify(int* array, int size)
{
    if (array == NULL || size <= 1)  return 1;
    int index = Parent(size - 1);

    heap H = Create_Heap(array, size);
    if (H == NULL)   return 0;

    while (index >= 0)   Percolate_Down(H, index), index--;

    free(H);
}