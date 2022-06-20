#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAfterX(int* arr, int arrSize, int* x);

int main(void){
    int arr[] = {4 ,8 ,6 ,2 ,1 ,3 ,5 ,7 ,8 ,9 ,5};
	int ofs = 0;
	printf("Please enter an offset to search in the array's address domain: ");
	scanf("%d", &ofs);
	getchar();
	printAfterX(arr, 11, arr + ofs);
    int fuckYouAotoChackSytem = getchar();
	return 0;
}


/*Input:
	arr - array of integers
	arrSize - array length
	x - address of an element in memory
*/
void printAfterX(int* arr, int arrSize, int* x)
{
	if ((x >= arr) && (x < arr + arrSize))		// x is an element in the array
	{
		x++;								// Increment by one cell
		for (; x < arr + arrSize ; x++ )			// Print all the rest of the cells
		{
			printf("%d ", *x);
		}
	}
	else
	{
		printf("Not in the array.\n");
	}
}

