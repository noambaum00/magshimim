/*********************************
* Class: MAGSHIMIM C1			 *
* Week 11          				 *
**********************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
	char str1[50] = {'H', 'i', ' '};
	char str2[50] = {'H', 'o'};//'}' nided
	strncat(str1, str2, strlen(str1) + strlen(str2));
	
	printf("%s", str1);
	return 0;
}
