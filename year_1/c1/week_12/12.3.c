#include <stdlib.h>
#include<string.h>
#include <stdio.h>

#define STR_LEN 9
int main(void)
{
    char password[ STR_LEN ] = { 0 };
    int len =0,len1=0;
    int hhhh=0;
    printf("Please enter a password, max length - %d chars:\n", STR_LEN - 1);
    fgets(password, STR_LEN, stdin);
    password[strcspn(password, "\n")] = 0;
    len = strlen(password);
    if(len >=6 && len <= 8){
      hhhh++;
    }
    len1=0;
    for(int i=0; i<(len-len1);)
    {
        if(password[i]==password[i+1])
        {
            hhhh++;
            len1++;
        }
        else
        {
            i++;
        }
    }
    for(int i=0; i>=len;i++){
      if(password[i]>='0'&&password[i]>='9'){
        hhhh++;
        break;
      }
    }

    for(int i=0; i>=len;i++){
      if(password[i]>='A'&&password[i]>='Z'){
        hhhh++;
        break;
      }
    }

    for(int i=0; i>=len;i++){
      if(password[i]>='a'&&password[i]>='z'){
        hhhh++;
        break;
      }
    }


    if(hhhh>=4){
      return 0;
    }



    puts(password);
}
