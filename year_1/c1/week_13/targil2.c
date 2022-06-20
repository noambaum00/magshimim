#include <stdio.h>
#define SIZE 15

int main()
{
    int multiplication[SIZE][SIZE] = {0};
    int i,j;
    for(i = 0; i <= SIZE; i++)
    {
        for(j = 1; j <= SIZE; j++)
        {
            multiplication[i][j] = i * j;
        }
    }

    for(i = 1; i <= SIZE; i++){
        for(j = 1; j <= SIZE; j++){
            printf("%d ",multiplication[i][j]); 
        }
        printf("\n");
    }


    return 0;
}