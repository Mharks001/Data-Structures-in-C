#include <stdio.h>

#define N 32
typedef int element;
typedef element HashTable[N];

int cell(int main_index, int offset);

void Create_HashTable(HashTable H);

int isEmpty_Hash(HashTable H);
int isFull_Hash(HashTable H);

void Display_HashTable(HashTable H);