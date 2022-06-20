#include <stdio.h>

int main (void)
{
  char first = 'a';
  char secend = 'a';
  char third = 'a';
  int year = 2000;
  int random = 64;
  printf("Write your name letter by letter\n");
  scanf("%c %c %c", &first,&secend,&third);
  printf("your name is %c%c%c\n",first,secend,third);
  printf("Write year Year of Birth and random number 1-100\n");
  scanf("%d %d", &year,&random);
  printf("The remainder of the division of your age in the other number is:%d" ,year%random );
  return 0;
}