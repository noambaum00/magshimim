/*********************************
* Class: MAGSHIMIM C2			 *
* Week 11           			 *
* Class Exercise Solution		 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode
{
	int val;
	struct IntNode* next;
} IntNode;


IntNode* concatenate(IntNode*, IntNode*);
IntNode* getInput(int size);
void printList(IntNode* list);
void freeList(IntNode* list);


int main(void)
{
	int size = 0;
	printf("How many nodes in first list? ");
	scanf("%d", &size);
	IntNode* list1 = getInput(size);
	printf("How many nodes in second list? ");
	scanf("%d", &size);
	IntNode* list2 = getInput(size);
	printf("The two lists connected:\n");
	IntNode* list3 = concatenate(list1, list2);
	printList(list3);
	freeList(list3); // enough to free the big list only! it contains all the nodes
	getchar();
	getchar();
}

//************************************
// Method:    getInput
// Returns:   IntNode* - return the newly created IntNode intoo previous link pointer
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
// Method:    concatenate
// Returns:   IntNode* - return head of the concatenated list
// Description: concatenate 2 linked lists
// Parameter: 2 lists
//************************************
IntNode* concatenate(IntNode* l1, IntNode* l2)
{
	IntNode* temp1 = l1;
	IntNode* temp2 = l2;
	IntNode* res = NULL;
	if (!l1) //checking for empty lists
	{
		res = l2;
	}
	else if (!l2)
	{
		res = l1;
	}
	else
	{
		while (temp1->next && temp2->next) // go to end of shorter list
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (!temp1->next)
		{
			temp1->next = l2;
			res = l1;
		}
		else
		{
			temp2->next = l1;
			res = l2;
		}
	}
	return res;
}

/**
Running time:
loop: in each iteration 4 operations (2 comparisons, 2 incrementation of list)
number of iterations= size of the shorter list-1. If n is size of the shorter list and m size of longer one, 
this function runs (n-1)*4 + constant, which is O(n) 
**/

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




