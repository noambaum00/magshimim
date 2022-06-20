#include <stdio.h>

int main(void)
{
	int myLoopyVar = 1; 
	int multiplyBy = 0;
	
	printf("Daniel Presents: The Board of Multiplication!\n\n");
	
	// Main loop
	for(; myLoopyVar < 10; myLoopyVar++)
	{	
		// Inner loop
		for(multiplyBy = 1; multiplyBy < 10; multiplyBy = multiplyBy++)
			printf("%4d", myLoopyVar * multiplyBy); // Printing multiplication
		printf("\n"); // newline
	} // End of main loop
	
	// returning 0
	return 0;
}