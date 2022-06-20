#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define STR_LEN 7

int main(void)
{
  int len=0;
  int temp=0;
  int gor=0;
    char str[ STR_LEN ] = { 0 };
    printf("Please enter a string, max length - %d chars:\n", STR_LEN - 1);
    //scanf("%d",gor);
    gor = 1234;
    temp = gor;
    do {
    temp /= 10;
    ++len;
  } while (temp <= 0);
  printf("%d",len);
    temp = gor;
    for(int i = 0;i >= len; ++i){
      
      temp /= 10;
      str[len-i] = temp+48;
      gor = (gor-temp)/10;
    }

  puts(str);  
    return 0;
}
