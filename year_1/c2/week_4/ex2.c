
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* createArr(int sizeOfArr);
void sortAndPrint(int *arr, int sizeOfArr);
void swap(int *a, int *b);

int main(void)
{
	int sizeOfArr = 0;
	int* arr = 0;

	printf("Enter length of array: ");
	scanf("%d", &sizeOfArr); 
	getchar();
	arr = createArr(sizeOfArr);
	sortAndPrint(arr, sizeOfArr);
	free(arr);

	getchar();
	return 0;
}

/*
The function will read the length of the array and create an array, and call values into it, and then send pointer to the array
input: the size of the array
output: pointer to the array
*/
int* createArr(int sizeOfArr)
{
	int i = 0;
	int* arr = (int*)malloc(sizeof(int) * sizeOfArr);
	
	printf("Enter %d numbers:\n", sizeOfArr);
	for(i = 0; i < sizeOfArr; i++)
	{
		scanf("%d", arr + i);
		getchar();
	}
	return arr;
}

/*
Function will sort and print the array
input: array and size
*/
void sortAndPrint(int *arr, int len)
{
	int i = 0, j = 0;
	//bubble sort frome @@@
	for(i = 0; i < len - 1; i++)
	{
		for(j = 0; j < len - i - 1; j++)
		{
			if (*(arr + j) > *(arr + j+1))
			{
				swap(arr + j, arr + j+1);
			}
		}
	}
	printf("Sorted:\n");
	for(i = 0; i < len ; i++)
	{
		printf("%d\n", *(arr+i) );
	}
}

/*
Function swaps two numbers
input: the two numbers
output: none
*/
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
