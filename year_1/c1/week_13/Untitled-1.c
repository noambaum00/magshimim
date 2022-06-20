#include <stdio.h>

int main(void){
    int all=0;
    char temp=0;

    printf("");
    scanf("%d",& temp);
    if(temp == 'a'){
        all++;
    }

    printf("");
    scanf("%d",& temp);
    if(temp == 'a'){
        all++;
    }

    printf("");
    scanf("%d",& temp);
    if(temp == 'a'){
        all++;
    }
    if(temp > 0){
        printf("asur");
        return 0;
    }
    return 1;
}