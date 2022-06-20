#include <stdio.h>
#include <math.h>

float series(int n,int r,int temp,float sum);

int main ()
{
  int a, num, r, temp, i;
  float sum = 0;
  printf ("Enter First element of the Series:  ");
  scanf ("%d", &a);
  printf ("Enter the Series Ratio:  ");
  scanf ("%d", &r);
  printf ("Enter the Numbers of element to display:  ");
  scanf ("%d", &num);
  temp = a;
  series(num,r,temp,sum);
  return 0;
}


float series(int num,int r,int temp,float sum){
  int i;
  for (i = 0; i < num; i++)
    {
      printf ("%d  ", temp);
      sum = sum + temp;
      temp = temp * r;
    }

}