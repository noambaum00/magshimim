/*********************************
* Class: MAGSHIMIM C2			 *
* Week 11           			 *
* HW Solution					 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode
{
	int val;
	struct IntNode* next;
} IntNode;


IntNode* getInput(int size);
void printList(IntNode* list);
void kLoop(IntNode**, int k);
void freeList(IntNode* list);

int main(void)
{
	IntNode* list = NULL;
	IntNode* kFromEnd = NULL;
	int size = 0;
	int k = 0;
	printf("How many nodes in list? ");
	scanf("%d", &size);
	list = getInput(size);
	printf("Choose a number k, and the list will be rotated k places to the left: ");
	scanf("%d", &k);
	kLoop(&list, k);
	printf("The rotated list:\n");
	printList(list);
	freeList(list);
	getchar();
	getchar();
}



//************************************
// Method:    getInput
// Returns:   IntNode* - return the newly created IntNode into previous link pointer
// Description: Gets input recursively
// Parameter: int size
//************************************
IntNode* getInput(int size)
{
	IntNode* node = (IntNode*)malloc(sizeof(IntNode));
	printf("Enter number: ");
	scanf("%d", &node->val);
	node->next = NULL;

	if (--size)
	{
		node->next = getInput(size);
	}

	return node;
}
//************************************
// Method:    printList
// Returns:   void
// Description: prints list recursively
// Parameter: IntNode * list
//************************************
void printList(IntNode* list)
{
	if (list)
	{
		printf("%d  ", list->val);
		printList(list->next);
	}
	else
	{
		printf("\n");
	}
}

//************************************
// Method:    freeList
// Returns:   void
// Description: Frees list recursively
// Parameter: intNode * list
//************************************
void freeList(IntNode* list)
{
	if (list)
	{
		freeList(list->next);
	}
	free(list);
}


//************************************
// Method:    kLoop
// Returns:   None
// Description: Turns the list by k elements
// Parameter: list pointer and an integer k
//************************************
void kLoop(IntNode** list, int k)
{
	IntNode* head = *list;
	IntNode* tail = *list;
	int i = 0;
	//Go to the end of the list
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = head;
	for (i = 0; i < k; i++)
	{
		tail = tail->next;
		head = head->next;
	}
	tail->next = 0;
	*list = head;
}

//This program makes only 2 pointer changes- the original tail is pointing to the head, and the kth element is pointing to null.

