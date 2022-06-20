#include <stdio.h>
#include <string.h>

#define PASSWORD "maGshimim2017"
#define STR_LEN 16
#define FALSE 0
#define TRUE !FALSE

// use getstr solve the problem.
void getstr(char str[], int size);

int main(void)
{
	int pass = FALSE;
    char buff[STR_LEN] = { 0 };

    printf("Enter the password: ");
    // scanf("%s", buff); Problem We haven't control over its size so it also changes the variable that is Next in  the memory: PASS;
	// the true way: 
	getstr(buff, STR_LEN);
    if(strcmp(buff, PASSWORD)){
        printf ("Wrong Password \n");
    }
    else{
        printf ("Correct Password \n");
        pass = TRUE;
    }

    if(pass)
    {
        printf ("Access given to the secret files \n");
    }
	
	getchar();
    return 0;
}


/*
Function will perform the fgets command and also remove the newline 
that might be at the end of the string - a known issue with fgets.
input: the buffer to read into, the number of chars to read
*/
void getstr(char str[], int size){
	fgets(str, size, stdin);
	str[strcspn(str, "\n")] = 0;
}
