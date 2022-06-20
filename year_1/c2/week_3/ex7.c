#include <stdio.h>
#define SIZE 11

int arrayNum(int* start, int* end);

int main(void)
{
	int arr[SIZE] = { 0 };
	int offset = 0, i = 0;
	int arraySize = 0;
	for (i = 0; i < SIZE; i++)
	{
		printf("Please enter a number for index %d: ", i);
		scanf("%d", arr + i);
		getchar();
	}

	printf("Please enter an index: ");
	scanf("%d", &offset);
	getchar();
	arraySize = arrayNum(arr, arr + offset);
	printf("%d\n", arraySize);
	getchar();
}

int arrayNum(int* start, int* end)
{
	return end - start + 1;
}