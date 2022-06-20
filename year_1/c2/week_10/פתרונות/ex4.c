/*********************************
* Class: MAGSHIMIM C2			 *
* Week 10           			 *
* HW Solution - Bonus			 *
* Finding a loop in a linked list*
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !FALSE

typedef struct intNode
{
	int data;
	struct intNode* next;
} intNode;

void freeList(intNode* list);
int isLooped(intNode* list);

int main(void)
{ 
	int loopy = FALSE;
	int toLoop = FALSE;

	// init list for test
	intNode* testList = (intNode*)malloc(sizeof(intNode));
	testList->next = (intNode*)malloc(sizeof(intNode));
	testList->next->next = (intNode*)malloc(sizeof(intNode));
	testList->next->next->next = (intNode*)malloc(sizeof(intNode));
	printf("Would you like to loop the list? 0 for no, anything else for yes\n");
	scanf("%d", &toLoop);
	getchar();
	if(toLoop)
	{
		testList->next->next->next->next = testList->next;
	}
	else
	{
		testList->next->next->next->next = NULL;
	}

	loopy = isLooped(testList);
	
	if (loopy)
	{
		printf("Yes, list is looped\n");
		// freeList(testList); // what happens when we try to free? how could we free the looped list?
	}
	else
	{
		printf("No, list is not looped\n");
		freeList(testList);
	}
	getchar();
	return 0;
}

//************************************
// Method:    freeList
// Returns:   void
// Description: Frees list recursively
// Parameter: intNode * list
//************************************
void freeList(intNode* head)
{
	if (head)
	{
		freeList(head->next);
	}
	free(head);
}

//************************************
// Method:    isLooped
// Returns:   is the list looped or not
// Description: use fast and slow jumps, if they meet it's looped, if null found its not. 
// Parameter: intNode * list
//************************************
int isLooped(intNode* list)
{
	intNode* walker = list;
	intNode* runner = list;

	int looped = FALSE;
	while (runner && runner->next && !looped)
	{
		runner = runner->next->next; // runner takes 2 steps
		walker = walker->next; // walker takes only one step

		if (walker == runner) // if and only if they ever meet, it means there is a loop
		{
			looped = TRUE;
		}
	}
	return looped;
}
