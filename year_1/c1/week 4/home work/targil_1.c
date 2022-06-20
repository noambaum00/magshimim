#include <stdio.h>

int main () {
  char a = 'h';
  char b = 'a';
  char c = 'a';
  printf("b=?\n");
  b = getchar();
  printf("c=?\n");
  scanf("%c",&c); getchar();
  printf("a= %c a+1=%c\n",a, a+1);
  printf("ASCII a= %d \n",a);
  printf("ASCII all= %d \n",a+b+c);
  getchar();
  printf("c= %c", c);
  putchar(c);
  return(0);
}
