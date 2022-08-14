#include "Sort.h"


int asc(int first, int second)  {return first <= second;}
int desc(int first, int second) {return first >= second;}

static void swap(int* A, int* B)
{
    int tmp = *A;
    *A = *B;
    *B = tmp;
}


static void Fusion(int* begin, int* end)
{
    if(begin == end)    return;

    queue Qa = CreateQueue();
    queue Qb = CreateQueue();
    int* current = begin;

    int i = *current;
    int j;

    while(current <= end && *current >= i) i = *current, EnQueue(&Qa, i), current++;
    while(current <= end)   EnQueue(&Qb, *current), current++;

    while(Front(Qa, &i) && Front(Qb,  &j))
    {
        if(i < j)
        DeQueue(&Qa), *begin = i;
        else
        DeQueue(&Qb), *begin = j;

        begin++;
    }
    while(Front(Qa, &i))    DeQueue(&Qa), *begin = i, begin++;
    while(Front(Qb, &j))    DeQueue(&Qb), *begin = j, begin++;
}
static int* Partition(int* low, int* high)
{
    if (low >= high) return low;

    int* pivot = low;
    low++;

    do {
        while (low <= high && *low <= *pivot)     low++;
        while (low <= high && *high > *pivot)    high--;
        if (low < high)  swap(low, high), low++, high--;
    } while (low <= high);

    swap(pivot, high);
    return high;
}

int isSorted(int* begin, int* end, int (*cmp)(int,int))
{
    for(;begin != end; begin++)
        if(!cmp(*begin, *(begin + 1)))
            return 0;
    return 1;
}

void MergeSort(int* begin, int* end)
{
    if(begin == end)    return;

    int* middle = (begin + (end-begin)/2);

    MergeSort(begin, middle);
    MergeSort(middle + 1, end);

    Fusion(begin, end);
}
void QuickSort(int* begin, int* end)
{
    if(begin == NULL || end == NULL || begin >= end)    return;

    int* pivot = Partition(begin, end);
    QuickSort(begin, pivot - 1);
    QuickSort(pivot + 1, end);
}
void HeapSort(int* array, int size)
{
    if (array == NULL || size <= 1)  return;
    
    Heapify(array, size);
    
    heap H = Create_Heap();
    if (H->array)    free(H->array);
    H->count = H->capacity = size;
    H->array = array;

    while (size--)
    {
        H->count--;
        swap(array, array + size);
        Percolate_Down(H, 0);
    }
}
// Depending on if Max_Heap or Min_Heap is included the HeapSort() sorts descendingly or ascendingly.
/*
* Version 2
void HeapSort(int* array, int size)
{
    heap H = Create_Heap();
    Build_Heap(H, array, size);
    int aux;
    while (GetMaximum_Heap(H, &aux)) DeleteMaximum_Heap(H), * (array + --size) = aux;
}
*/

void BubbleSort(int* begin, int* end, int (*cmp)(int, int))
{
    if(begin == NULL || end == NULL)    return;

    char flag = 1;
    for(int* i = begin; i <= end && flag; i++)
    {
        flag = 0;
        for(int* j = end; j > i; j--)
            if(!cmp(*(j-1), *j)) swap(j-1, j), flag = 1;
    }
}
void InsertionSort(int* begin, int* end, int (*cmp)(int, int)) 
{
    int* bound = begin + 1;
    int* aux = NULL;

    while (bound != end)
    {
        bound++;
        aux = bound;

        while (begin <= aux && !cmp(*(aux - 1),*aux))
            swap(aux, aux - 1), aux--;
    }
}
void SelectionSort(int* begin, int* end, int (*cmp)(int, int))
{
    if (begin == NULL || end == NULL || begin == end)    return;
    
    int* min = NULL;
    int* aux = NULL;

    while (begin != end)
    {
        aux = min = begin;
        
        while (aux <= end)
        {
            if (!cmp(*min, *aux))
                min = aux;
            aux++;
        }
        swap(begin, min);

        begin++;
    }
}