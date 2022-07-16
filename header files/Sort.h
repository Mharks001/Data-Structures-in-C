#include <stdio.h>
#include "Heap.h"
#include "DyQueue.h"

int asc(int first, int second);
int desc(int first, int second);

void MergeSort(int* begin, int* end);
void QuickSort(int* begin, int* end);

void BubbleSort(int* begin, int* end, int (*cmp)(int, int));