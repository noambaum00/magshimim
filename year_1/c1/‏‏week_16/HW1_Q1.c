/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
**********************************/

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int bobDylan = 50;

	int ummKulthum = 100; // ; needed
	int janisJoplin = 10;// why the \t?
	int johnnyCash = 90;
	int duduTasa = 12;
	// bobDylan | ummKulthum  |  janisJoplin  | johnnyCash
	// --------   -----------   -------------   ---------------
	johnnyCash /= 3;											//    50    |     100     |       10      |        30
	bobDylan = ummKulthum + janisJoplin+ * 3;	//+ not needed	//   ~??~   |     100     |      ~??~     |        30
	bobDylan += --johnnyCash + janisJoplin + ummKulthum;		//   ~??~   |     100     |      ~??~     |       ~??~

	printf("How many roads must a man walk down before you can call him a man?\n");
	printf("The answer my friend, is %d\n" bobDylan);
	getchar();
	return 0;
}
