#include <stdio.h>
#include <string.h>

#define STR_LEN 10 // use constants!

void printMessage(char str[]);

int main(void)
{
	char str[STR_LEN] = "THANK "; // string size was too small!
	char you[] = { 'u', 0 }; // can't use strncat on chars, only strings! so there's an error

	strncat(str, you, 1);
	printMessage(str);
	getchar();

	return 0;
}

/*
ENGLISH COMMENT:
Print the thank-you message
input: string to end the message
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