#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_HEAP_CAPACITY 32

typedef struct heap{
    int* data;
    int count;
    int capacity;
}*heap;

int Resize_Heap(heap H);
heap Create_Heap(int* array, int size);
heap Build_Heap(int* array, int size);

void Percolate_Up(heap H, int index);
void Percolate_Down(heap H, int index);

int Heapify(int* array, int size);