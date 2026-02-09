#include <stdio.h>

#define SIZE 100


int linearSearch(int arr[], int n, int key, int* count)
{
	*count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		(*count)++;

		if (arr[i] == key)
			return i;
	}
	return -1;
}


int binarySearch(int arr[], int n, int key, int* count)
{
	int left = 0;
	int right = n - 1;
	*count = 0;

	while (left <= right)
	{
		(*count)++;

		int mid = (left + right) / 2;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

int main()
{
	int arr[SIZE];

	// 정렬된 배열 생성 (1 ~ 100)
	for (int i = 0; i < SIZE; i++)
		arr[i] = i + 1;

	int key = 95;  // 뒤쪽 값 (차이 극대화용)

	int linearCount, binaryCount;

	int linearResult = linearSearch(arr, SIZE, key, &linearCount);
	int binaryResult = binarySearch(arr, SIZE, key, &binaryCount);

	printf("찾는 값: %d\n\n", key);

	if (linearResult != -1)
		printf("순차 탐색 성공 (인덱스 %d)\n", linearResult);
	else
		printf("순차 탐색 실패\n");

	printf("순차 탐색 비교 횟수: %d\n\n", linearCount);

	if (binaryResult != -1)
		printf("이진 탐색 성공 (인덱스 %d)\n", binaryResult);
	else
		printf("이진 탐색 실패\n");

	printf("이진 탐색 비교 횟수: %d\n", binaryCount);

	return 0;
}