#include "Quadratic_Probing_Hash.h"


int hash(element key) { return (key % N); }

int belong(HashTable H, element key)
{
	int index = hash(key);
	int offset = 0;
	
	for(int i = 0, value = 0; offset < N; i++, offset = i*i)
	{
		value = H[cell(index, offset)];
		
		if (value == -1)
			return 0;
		if (value == key)
			return 1;
	}
	return 0;
}

int insert_Hash(HashTable H, element key)
{
	int index = hash(key);
	int offset = 0;

	for (int i = 0; offset < N; i++, offset = i * i)
	{
		if (H[cell(index, offset)] == -1)
		{
			H[cell(index, offset)] = key;
			return 1;
		}
	}

	return 0;
}
int delete_Hash(HashTable H, element key)
{
	int index = hash(key);
	int offset = 0;

	for (int i = 0, value = 0; offset < N; i++)
	{	
		if (H[cell(index, offset)] == key)
		{
			H[cell(index, offset)] = -1;
			return 1;
		}
	}

	return 0;
}