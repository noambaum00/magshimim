#include <stdio.h>
#include<math.h>
int main(void) {
  long radius = 0;
  printf("what the radius?\n");
  scanf("%ld",&radius);
  printf("the Circle area is %.5f cm3\n",(pow(radius,3)*3.141592*4)/3);
  return 0;
}
