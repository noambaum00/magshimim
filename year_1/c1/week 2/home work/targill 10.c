#include <stdio.h>

int main(void) {
  int amichayAeg = 22, yairAeg = 18, harelAge = 15, naveAge = 13, oriyaAge = 12, ilayAge = 4;
  int dvirAge = 21, canaAge = 19, noamAge = 15, cockroachAge = 11;
  int grandfAge = 74, grandmAge = grandfAge-2;
  int princ = amichayAeg + yairAeg + harelAge + naveAge + oriyaAge + ilayAge;
  int baumgarten = dvirAge + canaAge + noamAge + cockroachAge;
  int Grandparents = grandfAge + grandmAge;
  int Grandchildren = princ + baumgarten;
  printf("total princ famaly = %d\n", princ);
  printf("total baumgarten famaly = %d\n\n\n", baumgarten);
  printf("total Grandchildren = %d\n", Grandchildren);
  printf("total Grandparents = %d\n", Grandparents);
  getchar();
  return 0;
}