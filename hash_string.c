#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

#define TABLE_SIZE 11
#define EMPTY ""

char hashTable[TABLE_SIZE][20];


int hashFunction(char* str)
{
	int sum = 0;
	for (int i = 0; str[i] != '\0'; i++)
		sum += str[i];

	return sum % TABLE_SIZE;
}


void initTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
		strcpy(hashTable[i], EMPTY);
}

void insert(char* key)
{
	int index = hashFunction(key);

	while (strcmp(hashTable[index], EMPTY) != 0)
	{
		index = (index + 1) % TABLE_SIZE;
	}

	strcpy(hashTable[index], key);
}

int search(char* key)
{
	int index = hashFunction(key);
	int start = index;

	while (strcmp(hashTable[index], EMPTY) != 0)
	{
		if (strcmp(hashTable[index], key) == 0)
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
		printf("[%d] : %s\n", i, hashTable[i]);
}

int main()
{
	initTable();

	insert("DATA");
	insert("STRUCTURE");
	insert("HASH");
	insert("SEARCH");

	printTable();

	int result = search("HASH");

	if (result != -1)
		printf("Å½»ö ¼º°ø! À§Ä¡: %d\n", result);
	else
		printf("Å½»ö ½ÇÆÐ!\n");

	return 0;
}
