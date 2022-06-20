#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arrayInput(int* arr,int arrSize);
int arrayReverseOutput(int* arr,int arrSize);

int main(void)
{
	int arr[10] = { 0 };
	arrayInput(arr, 10);
	arrayReverseOutput(arr, 10);
    getchar();
	return 0;
}



int arrayInput(int* arr,int arrSize){
    printf("Enter 10 numbers: ");
	for (int i = 0 ; i < arrSize; i++){
        scanf("%d", arr+i);
        getchar();
    }
}

int arrayReverseOutput(int* arr,int arrSize){
    printf("The numbers in revers order is: ");
    for(int i=arrSize-1; i >= 0; i--){
		printf("%d ", *(arr+i));
    }
}