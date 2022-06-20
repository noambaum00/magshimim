#include <stdio.h>
#include <stdlib.h>

#define SIDE 8
#define VISITED 1
#define NOT_VISITED 0

#define CORNER_1_X 7
#define CORNER_1_Y 7
#define CORNER_2_X 0
#define CORNER_2_Y 7
#define CORNER_3_X 7
#define CORNER_3_Y 0

#define FALSE 0
#define TRUE !FALSE

/**
This code takes a very long time to run! Checking all conditions takes a long time.
Read more here: https://en.wikipedia.org/wiki/Knight%27s_tour
**/


void printBoard(int board[][SIDE]);
int goHorsieBoard(int board[][SIDE], int x, int y, int step);
int allBoardVisited(int board[][SIDE]);

int main(void)
{
	int board[SIDE][SIDE] = {NOT_VISITED};
	int i = 0, j = 0;
	int res = FALSE;
	
	for(i = 0; i < SIDE && !res; i++)
	{
		for(j = 0; j < SIDE && !res; j++)
		{
			res = goHorsieBoard(board, i, j, 1);
		}
	}
	
	if(res)
	{
		printf("There is a path from %d,%d through the entire board! Here it is:\n",i,j);
		printBoard(board);
	}
	else
	{
		printf("No path from anywhere going through the entire board...");
	}
	getchar();
	return 0;
}


/*
Function checks if knight can travel from top left corner and travel the entire board
input: the board, and current step
output: whether a path was found
*/
int goHorsieBoard(int board[][SIDE], int x, int y, int step)
{
	int res = FALSE;
	if(x >= SIDE || y >= SIDE || x < 0 || y < 0 || // out of the board
			board[x][y] != NOT_VISITED) // we were here already!
	{
		res = FALSE;
	}
	else // make a move
	{
		board[x][y] = step;
		if(allBoardVisited(board))
		{
			res = TRUE;
		}
		else
		{
			step++;
			res = goHorsieBoard(board, x + 2, y + 1, step) ||
				  goHorsieBoard(board, x + 2, y - 1, step) ||
				  goHorsieBoard(board, x + 1, y + 2, step) ||
				  goHorsieBoard(board, x + 1, y - 2, step) ||
				  goHorsieBoard(board, x - 2, y + 1, step) ||
				  goHorsieBoard(board, x - 2, y - 1, step) ||
				  goHorsieBoard(board, x - 1, y + 2, step) ||
				  goHorsieBoard(board, x - 1, y - 2, step);
			if(!res)
			{
				board[x][y] = NOT_VISITED;
			}	
		}
	}
	return res;
}

/*
Function checks if all the board was visited
input: the board
output: whether all were visited
*/
int allBoardVisited(int board[][SIDE])
{
	int allVisited = TRUE;
	
	int i = 0, j = 0;
	for(i = 0; i < SIDE && allVisited; i++)
	{
		for(j = 0; j < SIDE && allVisited; j++)
		{
			allVisited = allVisited && (board[i][j] != NOT_VISITED);
		}
	}
	return allVisited;	
}

/*
Function prints the board
input: board to print
output: none
*/
void printBoard(int board[][SIDE])
{
	int i = 0, j = 0;
	for(i = 0; i < SIDE; i++)
	{
		for(j = 0; j < SIDE; j++)
		{
			printf("%3d", board[i][j]);
		}
		printf("\n");
	}
}
