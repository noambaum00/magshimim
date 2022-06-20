#include <stdio.h>
//4
int main(void) {
  int num = 0;   
  printf (" Enter a number to display the absolute value: ");  
  scanf ("%d", &num);  
  if(num >= 0){
    printf("the absolute is: %d",num);
  }
  else{
  printf("the absolute is: %d",num*-1);
  }
  return 0;
}