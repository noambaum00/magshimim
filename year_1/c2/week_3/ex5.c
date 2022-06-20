#include <stdio.h>

#define SIZE 5

void printArray(int* arr, int size);
int* createArray();

int main(void)
{
	int* pArr = 0;
	pArr = createArray();
	printArray(pArr, SIZE);
	
	getchar();
	return 0;
}

/*
Print array
input: the array and its size
*/
void printArray(int* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", *(arr + i));
	}
}

/*
Create array.
output: the address of new array.
*/
int* createArray()
{
	int arr[SIZE] = { 1, 2, 3, 4, 5 };
	return arr;
}



// becose the name of the array is His address.