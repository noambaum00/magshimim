#include <stdio.h>
 
int main()
{
  int i, Number, count, many=0; 
  
  printf("the prime Number from 1 to 1000 are: \n"); 
  for(Number = 1; Number <= 1000; Number++)
  {
    count = 0;
    for (i = 2; i <= Number/2; i++)
    {
  	if(Number%i == 0)
  	{
     	  count++;
	  }
    }
    if(count == 0 && Number != 1 )
    {
	    printf("%d\n", Number);
      many++;
    }  
  }
  printf("thare are %d Prime numbers\n",many);
  return 0;
}

