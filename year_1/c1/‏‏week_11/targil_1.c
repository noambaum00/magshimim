#include <stdio.h>

int main(void) {
  int nnnnnnnnnnn[5]={0};
  printf("Enter 5 number to array: ");
  for(int i =0; i<= 4; i++){
  scanf("%d",&nnnnnnnnnnn[i]);
  }
  printf("Array reversed:");
  for(int i =5; i>= 0; i--){
    printf("%d ",nnnnnnnnnnn[i]);
  }
  return 0;
}