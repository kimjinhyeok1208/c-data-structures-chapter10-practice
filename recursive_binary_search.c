#include <stdio.h>


int binarySearch(int arr[], int left, int right, int key)
{
	if (left > right)
		return -1;


	int mid = (left + right) / 2;

	if (arr[mid] == key)
		return mid;
	else if (arr[mid] > key)
		return binarySearch(arr, left, mid - 1, key);
	else if (arr[mid] < key)
		return binarySearch(arr, mid + 1, right, key);
}


int main()
{
	int arr[] = { 3,7,12,19,25,31,42 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 19;

	int result = binarySearch(arr, 0, n - 1, key);

	if (result != -1)
		printf("Å½»ö ¼º°ø! ÀÎµ¥½º: %d\n", result);
	else
		printf("Å½»ö ½ÇÆĞ!\n");

	return 0;
}