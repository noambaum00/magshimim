/*********************************
* Class: MAGSHIMIM C2			 *
* Week 11           			 *
* Bonus Solution				 *
**********************************/

#include <stdio.h>

int main(void)
{
	int x = 0;
	int y = 1;
	int z = 0;
	int sum = 0;

	do{
		z = x + y;
		x = y;
		y = z;
		if (y % 2 == 0)
		{
			sum += y;
		}
	} while (y <= 4000000);
	printf("Sum of even fibonacci elements: %d\n",sum);
}

// solution in a loop, not very creative - do you have a better one??
// This is O(n) - n being the largest fibonacci value we allow (in this case 4 million)