#include "Linear_Probing_Hash.h"

int hash(element key) { return (key % N); }


int belong(HashTable H, element key)
{
	int index = hash(key);
	int offset = 0;

	element value;

	while (offset < N && (value = H[cell(index, offset)]) != -1)
		if (value == key)	return 1;

	return 0;
}

int insert_Hash(HashTable H, element key)
{
	int index = hash(key);
	int offset = 0;

	while (H[(index + offset) % N] != -1 && offset < N)	offset++;
	if (offset == N)	return 0;

	H[(index + offset) % N] = key;
	return 1;
}
int delete_Hash(HashTable H, element key)
{
	int index = hash(key);
	int offset = 0;
	
	int rep_index;

	int origin_index;
	int current_index;

	int origin_offset;
	int current_offset;

	while (H[cell(index, offset)] != key && offset < N)	offset++;
	if (offset == N)	return 0;

	index = cell(index, offset);
	offset = 1;

	H[index] = -1;
	
	rep_index = index;

	while (offset < N && H[cell(index, offset)] != -1)
	{
		current_index = cell(index, offset);
		origin_index = hash(H[current_index]);

		if ((current_offset = current_index - rep_index) < 0)	current_offset += N;
		if ((origin_offset = origin_index - rep_index) < 0)	origin_offset += N;

		if (current_offset < origin_offset)
		{
			H[rep_index] = H[current_index];
			H[current_index] = -1;
			rep_index = current_index;
		}

		offset++;
	}
}