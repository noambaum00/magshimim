/*********************************
* Class: MAGSHIMIM C2			 *
* Week 6           				 *
* HW  solution				 	 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRO_OP 1
#define CON_OP 2
#define PRINT_OP 3
#define EXIT_OP 4

#define STR_LEN 50

typedef struct reasonList
{
	char* listName;
	char** reasons;
	int numReasons;
} reasonList;


void initList(reasonList* list, char* name);
void addReason(reasonList* list);
void printList(reasonList list);
int menu(void);
void myFgets(char str[], int n);


int main(void)
{
	reasonList proList = { 0, 0 };
	reasonList conList = { 0, 0 };
	char dillema[STR_LEN] = { 0 };
	int op = 0;

	initList(&proList, "PRO");
	initList(&conList, "CON");
	
	printf("What is your dillema?\n");
	myFgets(dillema, STR_LEN);

	while (op != EXIT_OP)
	{
		op = menu();
		
		switch (op)
		{
			case(PRO_OP) :
				addReason(&proList);
				break;
			case(CON_OP) :
				addReason(&conList);
				break;
			case(PRINT_OP) :
				printf("Your dillema:\n");
				printf("%s\n\n", dillema);
				
				printList(proList);
				printList(conList);
				break;
			case(EXIT_OP):
				break;
		}
	}
	printf("Good luck!\n");
	getchar();	
	return 0;
}

/*
Function will initialize a reason list
input: the list to init, and its name
output: none
*/
void initList(reasonList* list, char* listName)
{
	list->reasons = (char**)malloc(sizeof(char*) * 0);
	list->numReasons = 0;
	list->listName = (char*)malloc(sizeof(char) * STR_LEN);
	strncpy(list->listName, listName, STR_LEN);
}

/*
Function will add a reason to the list
input: the list to add to and its name
output: none
*/
void addReason(reasonList* list)
{
	char* reason = (char*)malloc(sizeof(char) * STR_LEN);
	printf("Enter a reason to add to list %s:\n", list->listName);
	myFgets(reason, STR_LEN);

	list->numReasons++;
	list->reasons = realloc(list->reasons, sizeof(char*) * list->numReasons);
	list->reasons[list->numReasons - 1] = reason;
}

/*
Function will print a list of reasons
input: the list
output: none
*/
void printList(reasonList list)
{
	int i = 0;
	printf("List %s\n", list.listName);
	printf("---------\n");
	for (; i < list.numReasons; i++)
	{
		puts(list.reasons[i]);
	}
	printf("\n");
}

/*
Function shows menu and returns user's choice
input: none
output: user's choice
*/
int menu(void)
{
	int op = 0;
	printf("Choose option:\n");
	printf("%d - Add PRO reason\n", PRO_OP);
	printf("%d - Add CON reason\n", CON_OP);
	printf("%d - Print reasons\n", PRINT_OP);
	printf("%d - Exit\n", EXIT_OP);
	scanf("%d", &op);
	while (op < PRO_OP || op > EXIT_OP)
	{ 
		printf("Invalid option. Try again: ");
		scanf("%d", &op);
	}
	getchar(); // clean buffer
	return op;
}

/*
Function will delete a list
input: the list to delete
output: none
*/
void deleteList(reasonList list)
{
	for (int i = 0; i < list.numReasons; i++)
	{
		free(list.reasons[i]);
	}
	free(list.reasons);
	
	free(list.listName);
}

/*
Function will perform the fgets command and also remove the newline
that might be at the end of the string - a known issue with fgets.
input: the buffer to read into, the number of chars to read
*/
void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}