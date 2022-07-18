#include "Heap.h"

heap Build_Heap(int* array, int size);

void Percolate_Up(heap H, int index);
void Percolate_Down(heap H, int index);

int Heapify(int* array, int size);