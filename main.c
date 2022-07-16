#include <stdio.h>
#include "header files/Sort.h"
// Type in WSL command line "runc"

int main()
{
	int arr[40] = {12124,121, 34,13,13,5,3,1,31, 2315, 32, 1325, 23134, 12,234,13,123124, 134134,2,4234,23,513,413,325424,5,542,5,523,4623,46,3623,462,56,3245,42,5,2656,2};
	//BubbleSort(arr, arr + 11, &asc);
	printf("Hello\n");
	MergeSort(arr, arr+29);
	for(int i = 0; i < 30; i++)
	printf("%i ", arr[i]);
	putchar('\n');
	return 0;
}