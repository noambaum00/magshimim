/*********************************
* Class: MAGSHIMIM C2			 *
* Week 10           			 *
* HW Solution - Magshiparty		 *
* Managing a line (queue)		 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 20
#define NUM_FRIENDS 3

typedef struct PersonNode
{
	char name[STR_LEN];
	int age;
	struct PersonNode* next;
} PersonNode;

// constant defenition
#define PRINT 1
#define ADD 2
#define REMOVE 3
#define VIP 4
#define SEARCH 5
#define REVERSE 6
#define EXIT 7

#define FALSE 0
#define TRUE !FALSE


// function declaration
int menu(void);
void printPerson(PersonNode* head);
int listLength(PersonNode* head);
void whoDoYouKnow(char friends[][STR_LEN]);
void add(PersonNode** head, PersonNode* person, char friends[][STR_LEN]);
PersonNode* initPerson(void);
PersonNode* createPerson(char* name, int age);
int areYouMyFriend(char* name, char friends[][STR_LEN]);
int removePerson(PersonNode** head, char* name);
int search(PersonNode* head, char* name);
void reverseLine(PersonNode** head);
void freePersons(PersonNode* next);
void myFgets(char str[], int n);


int main(void)
{
	// Variable declaration
	int choice = 0;
	PersonNode* head = NULL;
	PersonNode* guest = NULL;
	PersonNode* vip = NULL;
	char name[STR_LEN] = { 0 };
	char friends[NUM_FRIENDS][STR_LEN] = { { 0 }, { 0 }, { 0 } };

	while (choice != EXIT)
	{
		choice = menu();

		switch (choice)
		{
		case PRINT:
			printf("%d people in line:\n", listLength(head));
			printPerson(head);
			break;
		case ADD:
			printf("Welcome guest!\n");
			guest = initPerson();
			whoDoYouKnow(friends);
			add(&head, guest, friends);
			break;
		case REMOVE:
			printf("Enter name to remove:\n");
			myFgets(name, STR_LEN);
			printf("%s ", name);
			removePerson(&head, name) ? printf("removed from line\n") : printf("not in line\n");
			break;
		case VIP:
			printf("VIP GUEST!\n");
			vip = initPerson();
			vip->next = head;
			head = vip;
			break;
		case SEARCH:
			printf("Enter name to search:\n");
			myFgets(name, STR_LEN);
			printf("%s ", name);
			search(head, name) ? printf("found in line\n") : printf("not in line\n");
			break;
		case REVERSE:
			reverseLine(&head);
			printf("Line reversed!\n");
			break;
		case EXIT:
			freePersons(head);
			printf("Goodbye!");
			break;
		default:
			printf("Invalid input, please try again\n");
			break;
		}
	}
	getchar();

	return 0;
}


/*
Displays the menu
input: none
output: user's choice from the menu
*/
int menu(void)
{
	int choice = 0;
	printf("\nWelcome to MagshiParty Line Management Software!\n");
	printf("Please enter your choice from the following options:\n");
	printf("%d - Print line\n", PRINT);
	printf("%d - Add person to line\n", ADD);
	printf("%d - Remove person from line\n", REMOVE);
	printf("%d - VIP guest\n", VIP);
	printf("%d - Search in line\n", SEARCH);
	printf("%d - Reverse line\n", REVERSE);
	printf("%d - Exit\n", EXIT);
	scanf("%d", &choice);
	getchar(); // clean buffer
	return choice;
}

/*
Prints the linked list (recursively!)
input: head of list
output: none
*/
void printPerson(PersonNode* head)
{
	if (head)
	{
		printf("Name: %s, Age: %d\n", head->name, head->age);
		printPerson(head->next);
	}
}



/*
Function handles a new arrival of guest - getting her friends' names
input: memory to read the names into
output: none
*/
void whoDoYouKnow(char friends[][STR_LEN])
{
	int i = 0;
	printf("Enter names of 3 friends:\n");
	for (; i < NUM_FRIENDS; i++)
	{
		printf("Friend %d: ", i + 1);
		myFgets(friends[i], STR_LEN);
	}
}


/*
This function adds a person to the israeli line.
input: list, new person and her friends
output: none
*/
void add(PersonNode** head, PersonNode* person, char friends[][STR_LEN])
{
	PersonNode* curr = *head;
	int added = FALSE;

	if (curr == NULL) // list is empty
	{
	(*head) = person;
	}
	else if (areYouMyFriend(curr->name, friends)) // end condition 1
	{
	person->next = curr->next;
	curr->next = person;
	}
	else if (!(curr->next)) // end condition 2
	{
	((*head)->next) = person;
	}
	else
	{
	add(&(curr->next), person, friends); // recursion
	}
	
}

int areYouMyFriend(char* name, char friends[][STR_LEN])
{
	int i = 0;
	int iHaveAFriend = FALSE;
	for (; i < NUM_FRIENDS && !iHaveAFriend; i++)
	{
		iHaveAFriend = (0 == strcmp(name, friends[i]));
	}
	return iHaveAFriend;
}

int removePerson(PersonNode** head, char* name)
{
	PersonNode* temp = NULL;
	PersonNode* curr = *head;
	int removed = FALSE;
	if (*head) // list isn't empty
	{
		if (*head && 0 == strcmp((*head)->name, name)) // if first is the one to remove
		{
			temp = (*head)->next;
			free(*head);
			*head = temp;
			removed = TRUE;
		}
		else
		{
			// the next one isn't the one, and we are not on the last person
			while (!removed && curr->next && 0 != strcmp((curr->next)->name, name))
			{
				curr = curr->next;
			}
			
			if (curr->next && 0 == strcmp(curr->next->name, name)) // we got our person to remove!
			{
				temp = curr->next;
				curr->next = temp->next;
				free(temp);
				removed = TRUE;
			}
		}
	}

	return removed;

}


/*
Function searches for a person in the line
input: list and name to search for
output: was the person found
*/
int search(PersonNode* head, char* name)
{
	int found = FALSE;
	if (head) // line isn't empty
	{
		while (head && !found)
		{
			if (strcmp(head->name, name) == 0)
			{
				found = TRUE;
			}
			head = head->next;
		}
	}
	return found;	

}

PersonNode* initPerson(void)
{
	char name[STR_LEN] = { 0 };
	int age = 0;
	printf("Enter name: ");
	myFgets(name, STR_LEN);
	printf("Enter age: ");
	scanf("%d", &age);
	getchar(); // clean buffer
	return createPerson(name, age);
}

/*
Creates a person node in the memory
input: name and age of person
output: the node in the memory
*/
PersonNode* createPerson(char* name, int age)
{
	PersonNode* person = (PersonNode*)malloc(sizeof(PersonNode));
	strncpy(person->name, name, STR_LEN);
	person->age = age;
	person->next = NULL;
	return person;
}

/*
Frees list's memory
input: the list to free
output: none
*/
void freePersons(PersonNode* head)
{
	PersonNode* temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}



int listLength(PersonNode* head)
{
		
	int size = 0;
	if (head)
	{
		size = 1 + listLength(head->next);
	}
	return size;
}

/*
Function reverses line!
input: the line
output: none
*/
void reverseLine(PersonNode** head)
{
	PersonNode* first = *head;
	PersonNode* last = NULL;
	PersonNode* temp = NULL;

	if (*head == NULL || (*head)->next == NULL) // if list empty or has only one node or finished reversing
	{
	// finished - do nothing
	}
	else
	{
	first = *head;
	temp = first->next;
	reverse(&temp); // recursion, yay!
	first->next->next = first;
	first->next = NULL;

	*head = temp;
	}
	
}


void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}