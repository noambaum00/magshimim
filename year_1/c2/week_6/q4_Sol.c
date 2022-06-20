/*********************************
* Class: MAGSHIMIM C2			 *
* Week 5           				 *
* HW solution 				 	 *
**********************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* createBoard(int sizeOfBoard);
void printBoard(int *board, int sizeOfBoard);

int main(void)
{
	int sizeOfBoard =0;
	int *board=NULL;
	printf("Enter a number: ");
	scanf("%d", &sizeOfBoard);
	getchar();
	board = createBoard(sizeOfBoard);
	printBoard(board, sizeOfBoard);
	free(board);

	getchar();
	return 0;
}

/*	the function receives size of board (dimension)
	and create a math multiplication board in appropriate size.
	parameter - size of board
	return value: A pointer to first cell of board, NULL in case of error.
*/
int* createBoard(int sizeOfBoard)
{
	int i=0, j=0;
	int *board =NULL;
	
	board = (int*) malloc(sizeof (int) * sizeOfBoard * sizeOfBoard); // Allocation size: size of int * number of rows * number of columns.
	if (!board)
	{
		printf("Error Allocating memory");
		return NULL; // return NULL in case of failure.
	}
	
	//initialize board values
	for(i = 0; i < sizeOfBoard; i++)
	{
		for(j = 0; j < sizeOfBoard; j++)
		{
			// since we know how pointer arithmetic works, this is not too hard!
			*(board + i * sizeOfBoard + j) = (i+1) * (j+1); 
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
			printf("%3d", *(board + i*sizeOfBoard + j));
		}
		printf("\n");
	}
}