/*********************************
* Class: MAGSHIMIM C2			 *
* Week 11           			 *
* HW Helper File				 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode
{
	int val;
	struct IntNode* next;
} IntNode;


void printList(IntNode* list);
void freeList(IntNode* list);

int main(void)
{
	IntNode* list = NULL;
	printList(list);
	
	
	// TODO: HW
	
	
	getchar();
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
// Description: Frees list (recursively?)
// Parameter: intNode * list
//************************************
void freeList(IntNode* list)
{
	// TODO (kal)
}

