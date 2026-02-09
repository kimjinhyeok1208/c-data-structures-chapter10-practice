#include <stdio.h>

#define TABLE_SIZE 11
#define EMPTY -1

int hashTable[TABLE_SIZE];

int hashFunction(int key)
{
	return key % TABLE_SIZE;
}

void initTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
		hashTable[i] = EMPTY;
}


void insert(int key)
{
	int index = hashFunction(key);

	while (hashTable[index] != EMPTY)
	{
		index = (index + 1) % TABLE_SIZE;
	}

	hashTable[index] = key;
}

int search(int key)
{
	int index = hashFunction(key);
	int start = index;

	while (hashTable[index] != EMPTY)
	{
		if (hashTable[index] == key)
			return index;

		index = (index + 1) % TABLE_SIZE;

		if (index == start)
			break;
	}
	return -1;
}


void printTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
		printf("[%d] : %d\n", i, hashTable[i]);
}

int main()
{
	initTable();

	insert(22);
	insert(33);
	insert(44);
	insert(55);

	printTable();

	int key = 33;
	int result = search(key);

	if (result != -1)
		printf("Å½»ö ¼º°ø! À§Ä¡: %d\n", result);
	else
		printf("Å½»ö ½ÇÆÐ!\n");

	return 0;
}