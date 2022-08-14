#include <stdio.h>
#include "Min_Heap.h"
#include "DyQueue.h"

int asc(int first, int second);
int desc(int first, int second);

int isSorted(int* begin, int* end, int (*cmp)(int, int));

void MergeSort(int* begin, int* end);
void QuickSort(int* begin, int* end);
void HeapSort(int* array, int size);

void BubbleSort(int* begin, int* end, int (*cmp)(int, int));
void InsertionSort(int* begin, int* end, int (*cmp)(int, int));
void SelectionSort(int* begin, int* end, int (*cmp)(int, int));