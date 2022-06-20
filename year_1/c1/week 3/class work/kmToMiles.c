#include <stdio.h>

int main(void) {

  const float kmToMiles = 0.621371;
  int km  = 8;
  float miles = 0;
  miles = (kmToMiles*km);
  printf(" %d Kilometer in miles = %.3f",km,miles);

}
