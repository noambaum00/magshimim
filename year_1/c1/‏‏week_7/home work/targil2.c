#include <stdio.h>
int main() {
    int largest1 = 0, largest2 = 0, i, temp,num =0;

    printf("enter number(-999 to finish): ");
    scanf("%d", &num);
    while (temp != -999) {
        printf("enter number(-999 to finish:) ");
        scanf("%d", &temp);
        if(temp >= largest1) {
            largest2 = largest1;
            largest1 = temp;
        } else if(temp > largest2) {
            largest2 = temp;
        }
    }  
    printf("First and second largest number is %d and %d ", largest1, largest2);
}
