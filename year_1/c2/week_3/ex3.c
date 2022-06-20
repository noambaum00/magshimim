#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 50
#define ASCII_LITTLE_A 'a'
#define ABC_SIZE 26

void getstr(char str[], int size);
void decrypt(char* encText, int key);
void swapchar(char* a, char* b);

int main(void)
{
	char cipher[STR_LEN] = {0};
	int key = 0;
	printf("Enter cipher to decrypt: ");
	getstr(cipher, STR_LEN);
	printf("Enter decryption key: ");
	scanf("%d", &key);
	getchar();
	decrypt(cipher, key);
	printf("Decrypted text: ");
	puts(cipher);
	getchar();
	return 0;
}

/*
The function decrypts a text.
Input:
	string of encoded text
	key for the modulo
*/
void decrypt(char* encText, int key)
{
	int i = 0, len = strlen(encText);
	// revers the string.	
	strrev(encText);	
	for(i = 0; i < len; i++)
	{
		*(encText + i) = ((*(encText + i) - ASCII_LITTLE_A) + key) % ABC_SIZE + ASCII_LITTLE_A;
	}
}


/*
Function will perform the fgets command and also remove the newline 
that might be at the end of the string - a known issue with fgets.
input: the buffer to read into, the number of chars to read
*/
void getstr(char str[], int size)
{
	fgets(str, size, stdin);
	str[strcspn(str, "\n")] = 0;
}

/*
Function swaps two chars. 
input: the chars to swap
output: none
*/
void swapchar(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

