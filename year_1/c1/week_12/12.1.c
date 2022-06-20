#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isPalindrome(char str[]);


int main()
{
  char str[101]={0};
    printf("Enter string (max lenght 100 char): ");
    fgets(str, 100, stdin);
    isPalindrome(str);
    return 0;
}


// A function to check if a string str is palindrome

bool isPalindrome(char str[]){
    // Start from leftmost and rightmost corners of str
    int i = 0;
    int j = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (j > i)
    {
        if (str[i++] != str[j--])
        {
            printf("%s is not a palindrome\n", str);
            return 1;
        }
    }
    printf("%s is a palindrome\n", str);
    return 0;
}