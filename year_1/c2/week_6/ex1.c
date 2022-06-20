
#include <stdio.h>
#include <stdlib.h>


int getOperation(char * op);
void printUsage(void);

int main(int argc, char** argv)
{
	int resalt = 0;
	int a = 0;
	int aInd = 0;
	int operation = 0;
	int temp = 0;
	int temp2 = 0;
	
	if(argc < 4)//cose name, operation and 2 numbers
	{
		printf("ERROR! INVALID INPUT!\n");
		printUsage();
	}
	else
	{
		operation = getOperation(argv[1]);
		if (operation)
		{
			aInd = 2;
			resalt = atoi(argv[aInd]);
			aInd++;
			while (aInd < argc)
			{
				temp = atoi(argv[aInd]);
				temp2 = (temp * operation);
				resalt += temp2;
				aInd++;
			}
			printf("Result: %d", resalt);
		}
	}
	getchar();
	getchar();
	return 0;
}

/*
Function gets the correct operation
input: the operation
output: the operation's code
*/
int getOperation(char * answer)
{
	int resalt = 0;
	
	if(!strcmp(answer, "ADD"))
	{
		resalt = 1;
	}
	else if(!strcmp(answer, "SUB"))
	{
		resalt = -1;
	}
	else
	{
		printf("ERROR! INVALID COMMAND!\n");
		printUsage();
	}
	
	return resalt;
}

/*
Function prints the valid arguments number and order.
input: none
output: none
*/
void printUsage(void)
{
	printf("How to use the program: <ADD / SUB> <number> ... <number>");
}