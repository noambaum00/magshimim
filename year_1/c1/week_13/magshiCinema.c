/*********************************
* Class: MAGSHIMIM C1			 *
* Week 12           			 *
* Class solution 2  			 *
**********************************/

#include <stdio.h>

#define ROWS 5
#define SEATS_IN_ROW 3

#define CHEAP_TICKET_PRICE 25
#define NORMAL_TICKET_PRICE 35
#define VIP_TICKET_PRICE 50

void printCinema(int cinema[][SEATS_IN_ROW], int rows);
int catchPlace(int cinema[][SEATS_IN_ROW]);
int popcorn(int cinema[][SEATS_IN_ROW], int rows);
void moadon(int cinema[][SEATS_IN_ROW], int rows,int steat);
void nocrazyam(int cinema[][SEATS_IN_ROW], int rows,int newPrise);

int main(void)
{
	int cinema[ROWS][SEATS_IN_ROW] = {{CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, VIP_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE, NORMAL_TICKET_PRICE},
									  {CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE, CHEAP_TICKET_PRICE}};
	int catchPlace[ROWS][SEATS_IN_ROW]={0};
	int answer=0;
	printf("enter vomething(1-5(6 to exit)): ");
	scanf("%d",answer);

while (answer != 6)
{


	switch(answer)
{
    case 1:
      // statements
	  printf("enter vomething(1-5(6 to exit)): ");
	  scanf("%d",answer);
      break;

	case 2:
      // statements
	  printf("enter vomething(1-5(6 to exit)): ");
	  scanf("%d",answer);
      break;

	case 3:
      // statements
	  printf("enter vomething(1-5(6 to exit)): ");
	  scanf("%d",answer);
      break;

	case 4:
      // statements
	  printf("enter vomething(1-5(6 to exit)): ");
	  scanf("%d",answer);
      break;

	case 5:
      // statements
	  printf("enter vomething(1-5(6 to exit)): ");
	  scanf("%d",answer);
      break;

    default:
      printf("ERROR ENTER ANSWER AGAIN: ");
	  scanf("%d",answer);
}
}
	
	return 0;
}

/**
Print a cinema hall ticket prices
Input: 	hall, an; number of rows
Output: None
*/
void printCinema(int mat[][SEATS_IN_ROW], int rows)
{
	int row = 0;
	int col = 0;
	// TODO: continue
	for(row =0;row >= ROWS;row++){
		for (col =0; col>= SEATS_IN_ROW;col++){
			printf("%d ", mat[row][col]);
		}
		printf("\n");
	}
}

/*
A function that accepts the cinema hall, row number (between 0 and 4) and seat number (0-2)
and marks it as "occupied" by changing its value to minus 1(1-).
The function returns 1 if the purchase was made successfully,
and 0 if the seat was already occupied.
*/
int catchPlaces(int cinema[][SEATS_IN_ROW]){
	int rows=0, placeInRowd=0;
	printf("enter place num");
	scanf("%d%d",rows,placeInRowd);
	if(cinema[rows][placeInRowd]!=-1){
		cinema[rows][placeInRowd]=-1;
		return 1;
	}
	else return 0;
}

/*
A function that accepts the cinema hall and returns the number of occupied seats.
*/
int popcorn(int cinema[][SEATS_IN_ROW], int rows){
	int row = 0;
	int col = 0;
	int pop = 0;
	for(row =0;row >= ROWS;row++){
		for (col =0; col>= SEATS_IN_ROW;col++){
			if(cinema[row][col]==-1){
				pop++;
			}
		}
	}
	return pop;
}

/*
Function that receives the cinema hall, row number and seat number.
If the seat is not occupied, it reduces the price of the seat by 10%.
*/
void moadon(int cinema[][SEATS_IN_ROW], int rows,int steat){

	if(cinema[rows][steat]!=-1){
		cinema[rows][steat]=(cinema[rows][steat]/.1);
	}
		
}

/*
A function that receives the hall and a new price,
and updates the price of all the unoccupied seats in the hall to the new price.
*/
void crazy(int cinema[][SEATS_IN_ROW], int rows,int newPrise){
	int row = 0;
	int col = 0;
	int pop = 0;
	for(row =0;row >= ROWS;row++){
		for (col =0; col>= SEATS_IN_ROW;col++){
			if(cinema[row][col]!=-1){
				cinema[row][col]=newPrise;
			}
		}
	}
}
