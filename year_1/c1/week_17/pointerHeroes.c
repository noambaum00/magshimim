/*********************************
* Class: MAGSHIMIM C2			 *
* Week 2           				 *
* HW solution 			 		 *
**********************************/

#include <stdio.h>

void add(int* x, int* y, int* sum);

int main(void)
{
	int a = 0, b = 0, sum = 0;
	int *c = b;
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);
	getchar();
	add(&a, &c, &sum);
	printf("The sum of a and b is: %d", sum);
	getchar();
	return 0;
}


void add(int* x, int* y, int* sum) 
{ 
	sum = x + *y; 
}
