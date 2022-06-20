#include <stdio.h>

#define SAKALL_TO_DIRHAM 1.0873//XXX to SAKALL_TO_DIRHAM

int main()
{
  int shakal=1;//x to shakal
  printf("Welcome to United Arab Emirates, how many ILS you have?\n");
  scanf("%d",&shakal);//$x to &x
  printf("You have %.2f Dirham\n", SAKALL_TO_DIRHAM*shakal);//print to printF
  return 0;
}
