/*********************************
* Class: MAGSHIMIM C2			 *
* Week 11           			 *
* Bonus Solution				 *
**********************************/

#include <stdio.h>

//we mainly use the formula for sum of arithmetic sequence סדרה חשבונית
// 3, 6, 9, 12...this is an arithmetic sequence, and its sum has a formula: 
// http://www.mathwords.com/a/arithmetic_series.htm
// Run time: a constant number of operations, which is O(1).

int sumDivisbleBy(int n, int p);

int main(void)
{
	// all divisible by 3, plus all divisible by 5, minus all elements that are multiples of both!
	int result = sumDivisbleBy(3, 999) + sumDivisbleBy(5, 999) - sumDivisbleBy(15, 999);
	printf("Sum of all multiples of 3 or 5 below 1000: %d \n", result);

}
/**

*returns the sum of all number divided by p that are less or equal to n 

**/
int sumDivisbleBy(int n, int p)
{
	return n*(p / n)*((p / n) + 1) / 2;
}