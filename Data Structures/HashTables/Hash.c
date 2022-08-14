#include "Hash.h"

int cell(int main_index, int offset) { return (main_index + offset) % N; }

void Create_HashTable(HashTable H)
{
	for (int i = 0; i < N; i++)
		H[i] = -1;
}

int isEmpty_Hash(HashTable H)
{
	int index = 0;

	while (index < N)
		if (H[index] != -1)	return 0;

	return 1;
}
int isFull_Hash(HashTable H) {

	int index = 0;

	while (index < N)
		if (H[index] == -1)	return 0;

	return 1;
}

void Display_HashTable(HashTable H)
{
	printf("	******** Hash Start ********\n\n");
	for (int i = 0; i < N; i++)
	{
		printf("	%3i", i);
		if (H[i] != -1)	printf(" : %i", H[i]);
		putchar('\n');
	}

	printf("\n	********  Hash End  ********\n");
}