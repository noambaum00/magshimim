#include <stdio.h>
///3
int main(void) {
  int option = 0;
  int a;
  int  b;
  printf("please enter number option and 2 number:\n");
  scanf("%d %d %d", &option, &a,&b);
switch (option)
{
    case 1:
      printf("%d",a+b);
      break;

    case 2:
      printf("%d",a-b);
      break;

    case 3:
      printf("%d",a*b);
      break;

    case 4:
      printf("%d",a/b);
      break;

    default:
    printf("thus is not a vailet number");
      // default statements
}
  return 0;
}