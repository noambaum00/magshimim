#include <stdio.h>
#include <stdbool.h>

int main (void)
{
  char a  = 'a';
  a = getchar();
  if (a == 'y') {
   printf("yes");
  }
  else if (a == 'n') {
   printf("no");
}

  else {
   printf("FUZZY");
  }
  return 0;
}
