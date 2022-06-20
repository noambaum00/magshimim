#include <stdio.h>

int main(void) {
  char a = 'A';
  char z = 'Z';
  int allABC = z-a+1; //Because he does not count the first letter
  printf("a= %c\n" ,a);
  printf("b= %c\n" ,z);
  printf("%d" ,allABC);
  getchar();

}
