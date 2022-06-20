#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LENGTH 50

void myFgets(char str[], int size);
void getFrand(char** frand, int numFrand);
void sortFrand(char** frand, int numFrand);
void printFrand(char** frand, int numFrand);
void freeF(char** frand, int numFrand);
void swap(char *str1, char *str2);

int main(void){	
	int numFrand = 0;
	char** frand = NULL;
		
	printf("Enter number of frand: ");
	scanf("%d", &numFrand);
	getchar(); // clean buffer
	
	frand = (char**)malloc(sizeof(char*) * numFrand); // allocate array of pointers to names
	if(!frand) // malloc check
	{
		printf("Error allocating variables\n");
		return 1;
	}
	
	getFrand(frand, numFrand);
	sortFrand(frand, numFrand);
	printFrand(frand, numFrand);
	
	//freeing all allocated memory
	freeF(frand, numFrand);

	getchar();
	return 0;
}

/*
Function reads names of friends from user
input: array to read into, number of friends
output: none
*/
void getFrand(char** frand, int numFrand){
	char tempName[MAX_LENGTH] = {0};
	int i = 0;
	for(i = 0; i < numFrand; i++)
	{
		printf("Enter name of frand %d: ", i+1);
		myFgets(tempName, MAX_LENGTH);
		frand[i] = (char*)malloc(sizeof(char) * (strlen(tempName)+1));
		if(!frand[i])//if allocation failed
		{
			while(i) //free all previews successful allocations
			{
				i--;
				free(frand[i]);
			}
			free(frand);
			printf("\nError allocating variables\n");
			return;
		}
		strncpy(frand[i], tempName, strlen(tempName)+1);
	}
}

/*
Function sorts names of friends
input: array of friends, number of friends
output: none
*/
void sortFrand(char** frand, int numFrand){
	int i = 0, j = 0;
	char* temp = 0;
	
	for(i = 0; i < numFrand; i++) //bubble sort
	{
		for(j = 0; j < numFrand-1; j++)
		{
			if (strcmp(frand[j], frand[i]) > 0) //dictionary comparison
			{
				//swap(*frand[j], *frand[i]);
				//pointers swap
				temp = frand[i];
				frand[i] = frand[j];
				frand[j] = temp;
			}
		}
	}
}

/*
Function prints friends
input: array of friends, number of friends
output: none
*/
void printFrand(char** frand, int numFrand){
	int i = 0;
	for(i = 0; i < numFrand; i++)
	{
		printf("Friend %d: %s\n",i+1, frand[i]); //print names in abc order
	}
}


/*
Function free memory
input: array of friends, number of friends
output: none
*/
void freeF(char** frand, int numFrand){
	int i = 0;	
	for(i = 0; i < numFrand; i++)
	{
		free(frand[i]);
	}
	free(frand);
}

/*
fonction swap friends
input: two pointers to strings, number
output: none
*/

void swap(char *str1, char *str2){
  char *temp = str1;
  str1 = str2;
  str2 = temp;
}  


void myFgets(char str[], int size){
	fgets(str, size, stdin);
	str[strcspn(str, "\n")] = 0;
}
