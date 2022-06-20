#include <stdio.h>

int main(void) {
  int a=0,b=0;
  printf ("Write the first number");
  scanf ("%d", &a);
  printf ("Write the second number");
  scanf ("%d", &b);
  if(a==b){
    printf("The result is %d\n",b);
  }
  else{
    printf("The result is %d\n.",a * b);
  }
  printf("Press any key to continue . . ");
  getchar();
  return 0;
}