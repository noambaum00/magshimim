#include<stdio.h>
int main()
{
int i,j,num;
  printf("Enter a number: ");
  scanf("%d",&num);
  
  if(num>5 && num<20){

    for (i=1;i<=num;i++)
  {
    for(j=1;j<=i;j++)
    {
      printf("* ");
    }

    printf("\n");
  }
  
  }
  else{
    printf("ERROR\n%d is not enabled number",num);
  }

  return 0;
}
