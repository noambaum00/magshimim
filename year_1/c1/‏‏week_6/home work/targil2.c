#include <stdio.h>
int number, i=1;
long int fact = 1;
char y ='n';
int main()
{
do{
    
  printf("Enter a number to find the factorial: ");
  scanf("%d",&number);
  if(number==0){
    printf("error you should enter other number\n");

  }
  else{
do{
      fact *= i;
      i++;
    }while(i<=number);
  printf("Factorial of the given number %d is %ld\n", number, fact);
  }
  printf("do you wony to add a new number for factorial? (y/n) ");
  scanf("%s",&y);getchar();

}while(y == 'y');
return 0;
}
