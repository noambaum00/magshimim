#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
 
int arrayLen = 0;
// A recursive function that
// check a str[s..e] is
// palindrome or not.
bool isPalRec(char str[], int s, int e)
{
    // If there is only one character
    if (s == e)
    return true;
 
    // If first and last
    // characters do not match
    if (str[s] != str[e])
    return false;
 
    if (s < e + 1)
    return isPalRec(str, s + 1, e - 1);
 
    return true;
}
 
bool isPalindrome(char str[])
{
int len = strlen(str);
 
if (len == 0)
    return true;
 
return isPalRec(str, 0, len - 1);
}
 
// Driver Code



char* myFgets()
{
	char tempStr[50] = { 0 };
	char* str = NULL;
	fgets(tempStr, 50, stdin);
    arrayLen = 0;
	str = (char*)malloc(sizeof(char) * strlen(tempStr));
	tempStr[strcspn(tempStr, "\n")] = 0;
	strcpy(str, tempStr);
	return str;
}


int main()
{
    printf("Enter string: ");
    char* arr= myFgets();

 
    if (isPalindrome(arr))
    printf("Yes, it's a palindrome");
    else
    printf("not a palindrome");
 
    return 0;
}
