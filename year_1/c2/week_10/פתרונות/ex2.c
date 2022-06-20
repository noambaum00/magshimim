#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 20

typedef struct PersonNode
{
	char name[STR_LEN];
	int age;
	struct PersonNode* next;
} PersonNode;

PersonNode* initPerson(void);
PersonNode* createPerson(char* name, int age);
void printPerson(PersonNode* head);
void freePersons(PersonNode* next);
int PersonLen(PersonNode* head);
PersonNode* copyPerson(PersonNode* head);
void myFgets(char str[], int n);


int main(void)
{
	int people = 0, i = 0;
	PersonNode* head = NULL;
	PersonNode* curr = NULL;
	PersonNode* newPerson = NULL;
	printf("How many people in the list? ");
	scanf("%d", &people);
	getchar(); // clean buffer
	if (people > 0)
	{
		head = initPerson();
		curr = head;
	}
	for (i = 1; i < people; i++)
	{
		curr->next = initPerson();
		curr = curr->next;
	}

	printPerson(head);

	printf("num of people: %d\n", PersonLen(head));

	newPerson = copyPerson(head);

	printf("New list:\n");
	printPerson(newPerson);

	freePersons(head);
	freePersons(newPerson);
	getchar();
	return 0;
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


void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}



void printPerson(PersonNode* head)
{
	if (head)
	{
		printf("Name: %s, Age: %d\n", head->name, head->age);
		printPerson(head->next);
	}
}

PersonNode* copyPerson(PersonNode* head)
{
	PersonNode* copyHead = NULL;
	PersonNode* curr = NULL;

	if (head) // list to copy isn't empty
	{
		copyHead = createPerson(head->name, head->age);
		curr = copyHead;
		head = head->next;

		while (head)
		{
			curr->next = createPerson(head->name, head->age);
			curr = curr->next;
			head = head->next;
		}
	}
	return copyHead;
}


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


PersonNode* createPerson(char* name, int age)
{
	PersonNode* person = (PersonNode*)malloc(sizeof(PersonNode));
	strncpy(person->name, name, STR_LEN);
	person->age = age;
	person->next = NULL;
	return person;
}


int PersonLen(PersonNode* head)
{
	int size = 0;
	if (head)
	{
		size = 1 + PersonLen(head->next);
	}
	return size;
}






