/*********************************
* Class: MAGSHIMIM C2			 *
* Week 4           				 *
* HW solution   			 	 *
**********************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* createArr(int len);

int main(void)
{
	int size = 0;
	int* pArr = 0;

	printf("Enter a number of cells: ");
	scanf("%d", &size); // missing '&'
    pArr = createArr(size);
    printf("The array is at address %p: ", pArr);
    free(pArr);
    
	getchar();
	return 0;
}

/*
Function creates an array
input: number of cells in the array
output: pointer to the new array
*/
int* createArr(int size)
{
	int* pArr = (int*)malloc(sizeof(int) * size);// is bit not byte
	int i = 0;
	for(i = 0; i < size; i++)
	{
		printf("Please enter a number for index %d: ",i);
		scanf("%d", pArr + i); // wrong address
		getchar();//clean the buffer
	}
    //free(i); is static variable
	return pArr;
}
