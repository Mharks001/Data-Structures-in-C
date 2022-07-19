#include "Heap.h"


int isMaxHeap(heap H);

void Build_Heap(heap H, int* array, int size);

int GetMaximum_Heap(heap H, int* numref);
int DeleteMaximum_Heap(heap H);

void Percolate_Up(heap H, int index);
void Percolate_Down(heap H, int index);
int Heapify(int* array, int size);