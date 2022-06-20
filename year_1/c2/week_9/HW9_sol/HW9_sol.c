/*********************************
* Class: MAGSHIMIM C2			 *
* Week 9          				 *
* Homework solution			 	 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define FALSE 0
#define TRUE !FALSE

int isSubsetSum(int set[], int ind, int size, int sum);

// Driver program to test above function
int main(void)
{
	int* set = 0;
	int sum = 0;
	int size = 0;
	int i = 0;
	int answer = 0;
	printf("How many numbers in the set? ");
	scanf("%d",&size);
	set = (int*)malloc(size * sizeof(int));
	
	for(i = 0 ; i < size; i++)
	{
		printf("Enter number %d: ",i+1);
		scanf("%d", set+i);
	}
	printf("What is your the goal sum? ");
	scanf("%d",&sum);
	answer = isSubsetSum(set, size, 0, sum);
	answer ? printf("Yes, subset sum exists!") : printf("No subset sum found.");
	
	free(set);
	getchar();
	return 0;
}

/*
Function checks if there exists a subset sum in a set of numbers
input: set - the set of numbers
size - number of numbers in the set
ind - the current index which is being checked - is it in or out of the subset sum
sum - "goal"
output: if there is a subset with a sum same as the goal value
*/
int isSubsetSum(int set[], int size, int ind,  int sum)
{
	int success = 0;
	if (size == 0 && sum == 0) // sum is 0 and empty set
	{
		success = TRUE;
	}
	else if(ind == size && sum == 0) // reached the end and sum is exactly 0
	{
		success = TRUE;
	}
	else if(ind > size) // out of set borders - stop.
	{
		success = FALSE;
	}
    else if (set[ind] > sum) 
	{
		// skip set[ind] altogether, it is too big!
		success = isSubsetSum(set, size, ind+1, sum); 
	}
	else
	{
		success = isSubsetSum(set, size, ind+1, sum); // try skipping set[ind], if it didn't work...
		if (!success)
		{
			success = isSubsetSum(set, size, ind+1, sum-set[ind]); // including set[ind] in this subset, by subtracting its value from the desired sum
		} 
	}
	
	return success;
}