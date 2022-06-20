/*********************************
* Class: MAGSHIMIM C2			 *
* Week 6          			     *
* HW Solution 					 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct menuItem	
{
	char isSpicy; // 3 - Harif Esh!, 2 - Harif Ktzat, 1 - Harif Ba'Ktana, 0 - Lo Harif
	float price; // Item price
	char name[7]; // Item name
} menuItem;

int main(void)
{
	printf("sizeof(menuItem) = %d\n", sizeof(menuItem)); 
	/*
	For memory efficiency reasons, padding (ריפוד) is done so that memory is aligned with multiples of 4 / 8 bytes
	so that it is more easily accessed by the hardware.
	In the example aboue, the char "isSpicy" gets 4 bytes, even though he only needs one. And name gets 8 bytes (not 7).
	In the other variation, name+isSpicy is exactly 8 bytes, so no padding is needed.
	*/
	getchar();
	return 0;
}