#include <stdio.h>
#define MAX_NUM 100
#define MIN_NUM 1

int main(void)
{
	int num = 0;
	do
{
  printf("Please enter number between 1-100: ");
	scanf("%d", &num); 

}while(num > 100 || num < 1);
  printf("The number between 1-100: ");
	return 0;
}
