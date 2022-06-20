/*********************************
* Class: MAGSHIMIM C1			 *
* Week 9           				 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int areValidNumbers(int num1,int num2, int num3);
int returnRandoms(int lower, int upper);

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int chack = 0;
    
	do
{
    srand(time(0));
  num1 = returnRandoms(0, 100);
	num2 = returnRandoms(0, 100);
	num3 = returnRandoms(0, 100);
	chack = areValidNumbers(num1,num2, num3); 

}while(chack==3);
printf("-----%d-----\n",chack);
	printf("%d\n",num1);
	printf("%d\n",num2);
	printf("%d\n",num3);
	return 0;
}

/*
The function checks if all the conditions are met
input: all the number
output: the result (>3-fals; 3-true)
*/
int areValidNumbers(int num1, int num2, int num3)
{
	int ans = 0;
  
   if(num1 % 2==0 || num2 % 2==0 || num3 % 2==0){		//Checks if one of the numbers is positive
	   ans = ans + 1;
   }
   if(num1-1 % 2==0 || num2-1 % 2==0 || num3-1 % 2==0){	//Checks if one of the numbers is negative
	   ans = ans + 1;
   }
   if(num1 > 50 || num2 > 50 || num3 > 50){				//Checks if one of the numbers is greater than 50
	   ans = ans + 1;
   }
	return ans;
}

/*
The function checks if all the conditions are met
input: the lower and the upper number (For future use of the function)
output: "rumdom" number
*/
int returnRandoms(int lower, int upper)
{
  int num = (rand() % (upper - lower + 1)) + lower;
  return num;
    
}