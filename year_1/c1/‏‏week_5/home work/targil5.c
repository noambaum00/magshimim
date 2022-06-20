#include <stdio.h>
//5
int main(void) {
  int i = 0;
  printf("enter num\n");
  scanf("%d",&i);

  while(i<1||i>100) {
    printf("enter oder num\n");
    scanf("%d",&i);
  }
  printf("tank\n");
  return 0;
}