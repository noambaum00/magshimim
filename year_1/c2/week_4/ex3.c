#include <stdio.h>

/*
1. The function realloc, resize the memory block that was previously allocated. Using realloc we can increase or decrease the dynamic memory we need for an object.
2. realloc gets 2 parameters:
	a. a void-pointer to the memory block we previously allocated, and want to resize.
	b. unsigned integer that indicates the new size of the memory block- in bytes.
3. The function returns a pointer to the new memory block that was allocated.
4. There are 2 main good reasons for using realloc:
	a. when you need to keep your data, realloc will preserve the contents of the memory, so there's no need to copy it...
	b. if we use less memory than what we allocated at first, we can free it in a second and save some memory space.
*/

int main(void)
{

	//Write your code here...

	getchar();
	return 0;
