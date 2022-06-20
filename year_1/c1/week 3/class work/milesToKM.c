#include <stdio.h>

int main(void) {

  const float milestokm = 1.609344;
  int miles = 3;
  float km  = 0;
  km = (milestokm * miles);
  printf(" %d miles in Kilometer = %.3f" ,miles,km);

}