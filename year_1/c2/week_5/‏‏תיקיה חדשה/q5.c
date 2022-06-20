/*********************************
* Class: MAGSHIMIM C2			 *
* Week 6           				 *
* BONUS HW solution   			 *
**********************************/

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char* first = "literals";
	char* second = "literals";
	char third[] = { 'l', 'i', 't', 'e', 'r', 'a', 'l', 's', 0 };
	printf("first   ---  text:%s,  pointer:%p\n", first, first);
	printf("second  ---  text:%s,  pointer:%p\n", second, second); 
	// same as first! program checks if memory was already allocated for this string, and if so, doesn't allocate it again.
	// this depends on the compiler, and doesn't always happen.
	// see: http://stackoverflow.com/questions/39582578/printing-two-string-literals-with-same-value-gives-same-address
	// String literals are allocated in the data segment, a read-only part of the memory
	// see: http://stackoverflow.com/questions/4970823/where-in-memory-are-string-literals-stack-heap

	printf("third  ---  text:%s,  pointer:%p\n", third, third);
	// this memory was allocated on the stack, and may change (as we learned in the past)

	first[0] = 'a'; // crashes! string literals are stored in the data segment (read-only)

	third[0] = 'a'; // no problem.
	getchar();
	return 0;
}