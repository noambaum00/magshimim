#include <stdio.h>
//#define SAKALL_TO_UORO 0.29 המרה של הכסף
int main(void) {
  const float workInMonth = 20;//24
  const float workInDay = 8.5;
  const float manyForHour = 32.3/* *SAKALL_TO_UORO */;
  float manyForYear = 0;
  manyForYear = workInMonth*workInDay*manyForHour*12;
  printf("%f",manyForYear);
  return 0;
}