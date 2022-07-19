#include "Heap.h"

int isMinHeap(heap H);

void Build_Heap(heap H, int* array, int size);

int GetMinimum_Heap(heap H, int* e);
int DeleteMinimum_Heap(heap H);

void Percolate_Up(heap H, int index);
void Percolate_Down(heap H, int index);

int Heapify(int* array, int size);