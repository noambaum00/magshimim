#include <stdio.h>
//10
int main(void) {
  int num = 0;   
  printf (" Enter a number to display the absolute value: ");  
  scanf ("%d", &num);  
  num = num >= 0 ? num*-1 : num*1; 
  printf("the absolute is: %d",num*-1);
  
  return 0;
}