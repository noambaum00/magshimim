/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
**********************************/

#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	int bobDylan = 50;
	int ummKulthum = 100;
	int janisJoplin = 10;
	int johnnyCash = 90;
	// duduTasa was an unused variable!
																// bobDylan | ummKulthum | janisJoplin | johnnyCash
																// --------   -----------   -------------   ---------------
	johnnyCash /= 3;											//    50    |     100     |       10      |        30
	bobDylan = ummKulthum + janisJoplin++ * 3;					//   130    |     100     |       11      |        30
	bobDylan += --johnnyCash + janisJoplin + ummKulthum;		//    70    |     100     |       11      |       29

	printf("How many roads must a man walk down before you can call him a man?\n");
	printf("The answer my friend, is %d\n", bobDylan);
	getchar();
	return 0;
}
