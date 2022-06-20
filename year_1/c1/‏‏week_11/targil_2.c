#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_OF_FACES 6

int returnRandoms(int lower, int upper);

int main(void) {
  int sum=0;
  int nnn[100000]={0};
  int result[6]={0};
  	srand(time(NULL));
  for(int i; i <=10000;i++){
    sum = returnRandoms(1, 6);
    nnn[i]=sum;
    result[sum-1]= result[sum-1];
     
  }
  printf("1-%d   2-%d   3-%d   4-%d   5-%d   6-%d",result[0],result[1],result[2],result[3],result[4],result[5]);
  return 0;
}

int returnRandoms(int lower, int upper)
{
  int num = (rand() % (upper - lower + 1)) + lower;
  return num;
  
}