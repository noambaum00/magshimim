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

void printBoard(int board[][SIDE]);
int goHorsieCorners(int board[][SIDE], int x, int y, int step);
int aaa(int board[][SIDE]);

int main(void)
{
	int board[SIDE][SIDE] = {NOT_VISITED};
	if(goHorsieCorners(board, 0, 0, 1))
	{
		printf("Yes, there is a path from 0,0 through all corners! Here it is:\n");
		printBoard(board);
	}
	else
	{
		printf("No path from 0,0 through all corners");
	}
	getchar();
	return 0;
}


/*
Function checks if knight can travel from top left corner and travel through all corners
input: the board, and current step
output: whether a path was found
*/
int goHorsieCorners(int board[][SIDE], int x, int y, int step)
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
		if(allCornersVisited(board))
		{
			res = TRUE;
		}
		else
		{
			step++;
			res = goHorsieCorners(board, x + 2, y + 1, step) ||
				  goHorsieCorners(board, x + 2, y - 1, step) ||
				  goHorsieCorners(board, x + 1, y + 2, step) ||
				  goHorsieCorners(board, x + 1, y - 2, step) ||
				  goHorsieCorners(board, x - 2, y + 1, step) ||
				  goHorsieCorners(board, x - 2, y - 1, step) ||
				  goHorsieCorners(board, x - 1, y + 2, step) ||
				  goHorsieCorners(board, x - 1, y - 2, step);
			if(!res)
			{
				board[x][y] = NOT_VISITED;
			}	
		}
	}
	return res;
}


int aaa(int board[][SIDE])
{
	int visited = (board[CORNER_1_X][CORNER_1_Y] != NOT_VISITED &&
				   board[CORNER_2_X][CORNER_2_Y] != NOT_VISITED &&
			       board[CORNER_3_X][CORNER_3_Y] != NOT_VISITED);
	return visited;	
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
