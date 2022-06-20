/*********************************
* Class: MAGSHIMIM C2			 *
* Week 3           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <string.h>

void printArray(char* p, int len)
{
	//the not fixed code:
	/*
	for( p ; p < p + len ; p++ )//is infinite loop:		a < a+1	is alwase true.
	{
		printf("%c", *p);
	}
	printf("\n");
	*/
	//the fixed code:
	char * a = 0;
	for(a = p; a < p + len; a++)
	{
		printf("%c", *a);
	}
	printf("\n");


}

int main(void)
{
	char* msg = "hi jyegq meet me at 2 :)";//משהוא כאן לא עובד ככה
	printArray(msg, strlen(msg));
    getchar();
	return 0;
 }
