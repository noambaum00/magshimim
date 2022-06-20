#include<stdio.h>  
 int main()    
{    
int num=0, rev=0, a=0;    
printf("Enter a number: ");    
scanf("%d", &num);    

if(num>=1){
  while(num!=0)    
  {    
     a=num%10;    
     rev=rev*10+a;    
     num/=10;    
  }    
  printf("the reverse Number is: %d",rev); 
}
else{
  printf("ERROR\n%d is not enabled number",num); 
}  
return 0;  
}   
