#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* mallocBoard(int sizeBoard);
void printBoard(int *board, int sizeBoard);

int main(void)
{
	int sizeBoard =0;
	int *board=NULL;
	printf("Enter a number: ");
	scanf("%d", &sizeBoard);
	getchar();
	board = mallocBoard(sizeBoard);
	printBoard(board, sizeBoard);
	free(board);

	getchar();
	return 0;
}

/*	the function receives size of board (dimension)
	and create a math multiplication board in appropriate size.
	parameter - size of board
	return value: A pointer to first cell of board, NULL in case of error.
*/
int* mallocBoard(int sizeBoard)
{
	int i=0, j=0;
	int *board =NULL;
	
	board = (int*) malloc(sizeof (int) * sizeBoard * sizeBoard); // Allocation size: size of int * number of rows * number of columns.
	if (!board)
	{
		printf("Error Allocating memory");
		return NULL; // return NULL in case of failure.
	}
	
	//initialize board values
	for(i = 0; i < sizeBoard; i++)
	{
		for(j = 0; j < sizeBoard; j++)
		{
			// since we know how pointer arithmetic works, this is not too hard!
			*(board + i * sizeBoard + j) = (i+1) * (j+1); 
		}
	}

	return board;
}

/*
Function prints the board. 
input: the board and its size.
output: none
*/
void printBoard(int *board, int sizeOfBoard)
{
	int i=0, j=0;
	for(i = 0; i < sizeOfBoard; i++)
	{
		for(j = 0; j < sizeOfBoard; j++)
		{
			printf("%5d", *(board + i*sizeOfBoard + j));
		}
		printf("\n");
	}
}