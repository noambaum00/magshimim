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
IntNode* kLast(IntNode* l1, int k);
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
	printf("Choose a number k, and the k last values will be printed: ");
	scanf("%d", &k);
	kFromEnd = kLast(list, k);
	printf("The list from that node to the end:\n");
	printList(kFromEnd);
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
		printf("%d ", list->val);
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
// Method:    kLast
// Returns:   IntNode* - return the kth element from the end of the list
// Description: can assume the list is greater then k
// Parameter: list and an integer k
//************************************
IntNode* kLast(IntNode* l1, int k)
{
	IntNode* ans = l1;
	IntNode* last = l1;
	int count = 0;
	//move the temp pointer k elements
	for (count = 0; count < k; count++)
	{
		last = last->next;
	}
	//walk on the list with both pointers untill temp gets to the end of the list
	while (last)
	{
		last = last->next;
		ans = ans->next;
	}
	return ans;
}

/**
Running time:
let n be the length of the list
Function begins with 3 operations
first loop: k iterations, in each 3 operations: 
condition
move the pointer
count++
second loop: n-k iterations, in each 3 operations: 
condition
move 2 pointers

all together 3+3k+3*(n-k) = 3 + 3n 
which is clearly O(n)
**/