/*********************************
* Class: MAGSHIMIM C2			 *
* Week 11           			 *
* Class Exercise Solution		 *
**********************************/

#include <stdio.h>
#include<stdlib.h>

void function(int, int);
void function2(int, int);

int main(void)
{
	int a = 0, b = 0;
	printf("enter a number a \n");
	scanf("%d", &a);
	getchar();
	printf("enter a smaller number b \n");
	scanf("%d", &b);
	getchar();
	//printf("First function:\n");
	//function(a, b);
	
	//printf("Second function:\n");
	function2(a, b);
	getchar();
	return 0;
}


/**
a. This function prints all multiples of b that are smaller or equal to a.
b. The loop is performed a-b times
**/

//************************************
// Method:    function
// Returns:   void
// Description: prints all multiples of b that are less or equal to a
// Parameter:  integers a,b
//************************************
void function(int a, int b)
{
	int i = 0;
	for (i = a; i >= b; i--)
	{
		if (i % b == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

/**
c: In the next solution the loop is performed a/b times
**/

//************************************
// Method:    function
// Returns:   void
// Description: prints all multiples of b that are less or equal to a
// Parameter:  integers a,b
//************************************
void function2(int a, int b)
{
	int i = 0;
	for (i = b; i <= a; i +=b)
	{
		printf("%d ", i);
	}
	printf("\n");
}
