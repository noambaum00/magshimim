
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MIN_GRADE 0
#define MAX_GRADE 100

// i stole the signature.
// plase dont be angree on me.
void getAllGrades(int* gradesArr, int numOfGrades);
int getGrade(void);
int showMenu(void);
float getAverage(int* gradesArr, int numOfGrades);
void changeGrade(int* gradesArr, int numOfGrades);
void changeArrayLen(int** gradesArr, int* numOfGrades);
void printGrades(int* gradesArr, int numOfGrades);

int main(void)
{
	int numOfGrades = 0;
	int* grades = NULL;
	int chose = 0;
	printf("Enter number of grades: ");
	scanf("%d", &numOfGrades);
	getchar(); //buffer cleaning
	grades = (int*)malloc(sizeof(int) * numOfGrades);
	
	getAllGrades(grades, numOfGrades);
	chose = showMenu();
	
	while(chose != 5)
	{
		switch(chose)
		{
			case(1):
				printf("The grades average is: %.2f\n", getAverage(grades, numOfGrades));
				break;
			case(2):
				changeGrade(grades, numOfGrades);
				break;
			case(3):
				// sending addresses because we want to change them!
				changeArrayLen(&grades, &numOfGrades);
				break;
			case(4):
				printGrades(grades, numOfGrades);
				break;
			default:
				break;
		}
		chose = showMenu();
	}			
	free(grades);
	getchar();
	return 0;
}

/*
Function fills array with grades
input: array and its length
output: none
*/
void getAllGrades(int* gradesArr, int numOfGrades)
{
	int i = 0;
	for(i = 0; i < numOfGrades; i++)
	{
		printf("Enter grade %d: ", i+1);
		*(gradesArr+i) = getGrade();
	}
}

/*
Function reads a valid grade from user
input: none
output: a valid grade
*/
int getGrade(void)
{
	int grade = 0;
	scanf("%d", &grade);
	getchar();
	while(!(grade >= MIN_GRADE && grade <= MAX_GRADE))
	{
		printf("Invalid grade. 0-100 only. Try again: ");
		scanf("%d", &grade);
		getchar();
	}
	return grade;	
}

/*
Function shows menu and gets user's choice
input: none
output: user's choice
*/
int showMenu(void)
{
	int chose = 0;
	printf("1 - Calculate average\n");
	printf("2 - Change a grade\n");
	printf("3 - Change number of grades\n");
	printf("4 - Print grades\n");
	printf("5 - Exit\n");
	printf("Choose option: ");
	scanf("%d", &chose); 
	getchar();
	while(!(chose >= 1 && chose <= 5))
	{
		printf("Invalid choice. Try again: ");
		scanf("%d", &chose);
		getchar();
	}
	return chose;
}

/*
Function calculates average of numbers
input: array and its length
output: average of numbers 
*/
float getAverage(int* gradesArr, int numOfGrades)
{
	float sum = 0.0;
	int i = 0;
	for(i = 0; i < numOfGrades; i++)
	{
		sum += (float)*(gradesArr+i);
	}
	return (sum / numOfGrades);

}

/*
Function lets user change a grade
input: array of grades, and its length
output: none
*/
void changeGrade(int* gradesArr, int numOfGrades)
{
	int change = 0;
	
	printf("Which grade would you like to change? 1-%d: ", numOfGrades);
	scanf("%d", &change);
	getchar();
	while(!(change >= 1 && change <= numOfGrades))
	{
		printf("Invalid choice. Try again: ");
		scanf("%d", &change);
		getchar();
	}
	printf("Enter new grade: ");
	*(gradesArr+(change-1)) = getGrade();//?? *()
}

/*
Function changes length of array
input: array of grades, and its length
output: none
*/
void changeArrayLen(int** gradesArr, int* numOfGrades)
{
	int newLen = 0;
	printf("Enter new number of grades: ");
	scanf("%d", &newLen);
	*gradesArr = (int*)realloc(*gradesArr, sizeof(int) * newLen);
	
	while(*numOfGrades < newLen)
	{
		printf("Enter grade %d: ", (*numOfGrades)+1);
		(*gradesArr)[*numOfGrades] = getGrade();
		(*numOfGrades)++;
	}
	*numOfGrades = newLen;
}

/*
Function prints all grades
input: array and its length
*/
void printGrades(int* gradesArr, int numOfGrades)
{
	int i = 0;
	for(i = 0; i < numOfGrades; i++)
	{
		printf("%d ", gradesArr[i]);
	}
	printf("\n");
}