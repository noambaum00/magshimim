/*********************************
* Class: MAGSHIMIM C2			 *
* Week 2           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <time.h>

#define RANGE 10

void mystery(int*,int*);
void swap(int* x, int* y);

int main(void)
{
	int a = 0, b = 0;
	srand(time(NULL)); // seed for rand
	a = (rand() % RANGE) + 1;
	b = (rand() % RANGE) + 1;
	
	mystery(&a, &b);
	printf("a: %d b: %d \n", a, b);	

	return 0;
}

/*
A function checks if X is biger than Y:
input: two pointers of int
output: none
*/
void mystery(int* x, int* y)
{
	if(*x < *y)
	{
		*x = *x + *y;
	}
	else{
		*y = *x - *y;
	}
}

/*
A function replaces a value of two variablesinput: two pointers of int
output: none
*/
void swap(int* x, int* y)
{
	int* temp = x;
  x =y;
  y = temp;
}



/*
qestion 1: yes the funsion chang the value of the variable.
  the function go to their location in memory.
*/