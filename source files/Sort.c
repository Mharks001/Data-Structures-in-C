#include "../header files/Sort.h"


int asc(int first, int second)  {return first < second;}
int desc(int first, int second) {return first > second;}

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

void MergeSort(int* begin, int* end)
{
    if(begin == end)    return;

    int* middle = (begin + (end-begin)/2);

    MergeSort(begin, middle);
    MergeSort(middle + 1, end);

    Fusion(begin, end);
}

static int* Partition(int* low, int* high)
{
    if(low >= high) return low;

    int* pivot = low;
    low++;

    do{
        while(low <= high && *low <= *pivot)     low++;
        while(low <= high && *high > *pivot)    high--;
        if(low < high)  swap(low, high), low++, high--;
    }while(low <= high);

    swap(pivot, high);
    return high;
}

void QuickSort(int* begin, int* end)
{
    if(begin == NULL || end == NULL || begin >= end)    return;

    int* pivot = Partition(begin, end);
    QuickSort(begin, pivot - 1);
    QuickSort(pivot + 1, end);
}


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