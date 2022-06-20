/*********************************
* Class: MAGSHIMIM C2			 *
* Week 2           				 *
**********************************/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/*
* Function to print an array
*/
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int i = 0, j = 0;
	int arr[] = { 4, 2, 1, 3 };
	printf("Before sorting the array:\n");
	printArray(arr, SIZE);
	for (i = 0; i < SIZE - 1; i++)
	{
		for (j = 0; j < SIZE - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	printf("After sorting the array:\n");
	printArray(arr, SIZE);
	getchar();
	return 0;
}