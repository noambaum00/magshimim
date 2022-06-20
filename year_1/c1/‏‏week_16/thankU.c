/*********************************
* Class: MAGSHIMIM C2			 *
* Week 1           				 *
* HW Question - Thanks Program 	 *
**********************************/

#include <stdio.h>
#include <string.h>

void printMessage(char str[]);

int main(void)
{
	char str[6] = "THANK ";
	char you = 'u';
	
	strncat(str, you, 1); // do not fix this line or the next one
	printMessage(str); 
	return 0;
}

/*
מדפיס תודה וברכה
*/
void printMessage(char str[])
{
	printf("Hello Sigal! I just wanted to say that studying with you...\n\n");
	printf("Really made me understand how much I love\n");
	printf(" __  __                 _     _           _           \n");
	printf("|  \\/  |               | |   (_)         (_)          \n");
	printf("| \\  / | __ _  __ _ ___| |__  _ _ __ ___  _ _ __ ___  \n");
	printf("| |\\/| |/ _` |/ _` / __| '_ \\| | '_ ` _ \\| | '_ ` _ \\ \n");
	printf("| |  | | (_| | (_| \\__ \\ | | | | | | | | | | | | | | |\n");
	printf("|_|  |_|\\__,_|\\__, |___/_| |_|_|_| |_| |_|_|_| |_| |_|\n");
	printf("              __/ |                                  \n");
	printf("              |___/                                  \n\n");
	
	printf("Without C you would be just Gal :D\n");
	printf("See you in class!\n");
	printf("and %s !!", str);
	
}