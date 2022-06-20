#include <stdlib.h>
#include <stdio.h>

/*
The program gets two numbers and a choice of a math operation and performs it (if possible)
Input: None
Output: The program returns 0 upon successful completion of its running
*/
int main(void)
{
	// variables definition
	int num1 = 0, num2 =0;
	int* p1 = 0; /* added in א'*/
	int* p2 = 0; /* added in א'*/
	unsigned int choice = 0;
	p1 = &num1;
	p2 = &num2;
	
	//getting numbers from user
	printf("please enter the first number (a): ");
	scanf("%d", p1); /* added in ב'*/
	getchar();
	printf("please enter the second number (b): ");
	scanf("%d", p2); /* added in ב'*/
	getchar();

	//printing menu
	printf("\nWelcome to the Magashimim Calculator!");
	printf("\nPlease choose the math operation:");
	printf("\n1.	adding a+b");
	printf("\n2.	subtracting a-b");
	printf("\n3.	multiplying a*b");
	printf("\n4.	dividing a/b");

	//getting choice from user
	printf("\nYour choice: ");
	scanf("%d", &choice);
	getchar();

	printf("\n\n");
	
	//acting according to choice
	switch (choice)
	{
		case 1: //adding
			//printf("%d + %d = %d\n", num1, num2, num1 + num2);
			printf("%d + %d = %d\n", *p1, *p2, *p1 + *p2); /* added in ג'*/
			break;
		case 2: //subtracting
			//printf("%d - %d = %d\n", num1, num2, num1 - num2);
			printf("%d - %d = %d\n", *p1, *p2, *p1 - *p2); /* added in ג'*/
			break;
		case 3: //multiplying
			//printf("%d * %d = %d\n", num1, num2, num1*num2);
			printf("%d * %d = %d\n", *p1, *p2, (*p1) * (*p2)); /* added in ג'*/
			break;
		case 4: //dividing
			if (num2 == 0) //check for division by zero
			{
				printf("can't divide by zero!!!\n");
			}
			else
			{
				//printf("%d / %d = %.2f", num1, num2, (float)num1 / num2); //casting, because we will get fructions
				printf("%d / %d = %.2f", *p1, *p2, (float)(*p1) / (*p2)); /* added in ג'*/
			}
			break;
		default: //if the user didn't choose between 1-4
			printf("choice is not valid\n");
	}
	getchar();
	return 0;
} 