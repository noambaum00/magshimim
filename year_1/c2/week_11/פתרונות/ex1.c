/*********************************
* Class: MAGSHIMIM C2			 *
* Week 11           			 *
* Class Exercise Solution		 *
**********************************/

#include <stdio.h>
#include <math.h>


void allSqrs(int n);

int main(void)
{
	int n = 0;
	printf("Enter a number: ");
	scanf("%d", &n);
	getchar();
	printf("All squares less than %d:\n", n);
	allSqrs(n);
	getchar();
}
//************************************
// Method:    all_sqrs
// Returns:   void
// Description: prints all sqrs untill n
// Parameter:  integer n 
//************************************
void allSqrs(int n)
{
	int i = 0;
	double sqN = sqrt(n);
	for (i = 1; i <= sqN; i++)
	{
		printf("%d ", i*i);
	}
}

/** The running time of this function is:
2 operations in the beggining.
the loop- in each iteration 3 operation- 
1 check the condition
2 print
3 increase i
--> all together 3*sqrt(n)+2
O(sqrt(n))
**/
