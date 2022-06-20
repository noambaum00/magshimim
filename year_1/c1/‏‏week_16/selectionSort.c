/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printArray(int arr[], int size);

int main(void)
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int i = 0, j = 0, minIndex = 0, tmp = 0;

	printf("Before sorting the array:\n");
	printArray(arr, SIZE);

	for (i = 0; i < SIZE - 1; i++)
	{
		// Find the minimum element in the remaining unsorted array 
		minIndex = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		// Swap the found minimum element with the first element 
		tmp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = tmp;
	}

	printf("After sorting the array:\n");
	printArray(arr, SIZE);
	getchar();
	return 0;
}
/*
* Function to print an array
*/
void printArray(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}