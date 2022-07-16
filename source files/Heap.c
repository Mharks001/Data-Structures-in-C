#include "../header files/Heap.h"

//Max Heap

static void swap(int* A, int* B)                { int tmp = *A; *A = *B; *B = tmp; }

static void fill(heap H, int index, int data)   { *(H->data + index) = data; Precolate_Down(H, index); Precolate_Up(H, index);}
static void value(heap H, int index)            { if(index > H->count) return ;   return *(H->data + index); }
static void insert(heap H, int data)            { if(H->count == H->capacity) Resize_Heap(H);   fill(H, H->count++, data);}

static int Parent(int child_index)              { return (child_index - 1)/2; }
static int Right_Child(int parent_index)        { return 2*parent_index + 1; }
static int Left_Child(int parent_index)         { return 2*parent_index + 1; }

int Resize_Heap(heap H)
{
    if( H == NULL ) return 0;
    
    int* second = (int*)malloc(sizeof(int)*2*H->capacity);
    if(second == NULL)  return 0;

    int* aux = H->data;
    int index = 0, size = H->count;
    
    while(index < size) *(second + index) = *(aux + index), index++;
    
    free(H->data);
    H->data = second;

    return 1;
}

heap Create_Heap(int* array, int size)
{
    heap H = (heap)malloc(sizeof(struct heap));
    if(H == NULL)   return NULL;
    
    H->data = array;
    H->count = H->capacity = size;
    
    return H;
}

heap Build_Heap(int* array, int size)
{
    if(array == NULL || size == 0)  return NULL;

    heap H = (heap)malloc(sizeof(struct heap));
    if(H == NULL)   return NULL;
    
    H->capacity = DEFAULT_HEAP_CAPACITY;
    H->count = 0;
    
    H->data = (int*)malloc(sizeof(int)*DEFAULT_HEAP_CAPACITY);
    if(H->data == NULL) { free(H); return NULL; }

    for(int i = 0; i < size; i++) insert(H, *(array + i));

    return H;
}

void Percolate_Up(heap H, int index)
{
    if(index <= 0 || index > H->count)   return;
    
    int parent_index = Parent(index);
    
    int extremum = index;

    if(parent_index < H->count && parent_index >= 0 && *(H->data + extremum) > *(H->data + parent_index))   extremum = parent_index;

    if(extremum == index)   return;
    
    swap(H->data + index, H->data + extremum);
    Precolate_Up(H, extremum);
}

void Percolate_Down(heap H, int index)
{
    if(index < 0 || index > H->count)   return;
    
    int left_index = Left_Child(index);
    int right_index = Right_Child(index);
    int extremum = index;
    
    if(left_index < H->count && left_index >= 0 && *(H->data + extremum) > *(H->data + left_index))   extremum = left_index;
    if(right_index < H->count && right_index >= 0 && *(H->data + extremum) > *(H->data + right_index))   extremum = right_index;

    if(extremum == index)   return;
    
    swap(H->data + index, H->data + extremum);
    Precolate_Down(H, extremum);
}



int Heapify(int* array, int size)
{
    if(array == NULL || size <= 1)  return 1;
    int index = Parent(size - 1);
    
    heap H = Create_Heap(array, size);
    if(H == NULL)   return 0;

    while(index >= 0)   Percolate_Down(H, index), index++;
    
    free(H);
}

