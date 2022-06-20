#include <stdio.h>

#define MAXJanuary = 31 
#define MAXFebruary = 28 
#define MAXMarch = 31 
#define MAXApril = 30
#define MAXMay = 31 
#define MAXJune = 30
#define MAXJuly = 31 
#define MAXAugust = 31 
#define MAXSeptember = 30
#define MAXOctober = 31
#define MAXNovember = 30 
#define MAXDecember = 31 

enum month{January=1,February,March,April,May,June,July,August,September,October,November,December};
enum day{Sunday=1, Monday, Tuesday, Wednesday,Thursday,Friday, Saturday};

int dayInWeek(int month,int day,int weekDay);                                                 


int main(void) {
  enum month monthChoise=0;
  enum day dayhChoise=0;
  int maxday=0;

  do{
    printf("enter month(1-12): ");
    scanf("%d",&monthChoise);
    switch (monthChoise){
    case 1:
      maxday=31;
      break;

    case 2:
      maxday=28;
      break;
    case 3:
      maxday=31;
      break;
    case 4:
      maxday=30;
      break;
    case 5:
      maxday=31;
      break;
    case 6:
      maxday=30;
      break;
    case 7:
      maxday=31;
      break;
    case 8:
      maxday=31;
      break;
    case 9:
      maxday=30;
      break;
    case 10:
      maxday=31;
      break;
    case 11:
      maxday=30;
      break;
    case 12:
      maxday=31;
      break;

    default:
    return "ERROR";
  }
}while(monthChoise>=1&&monthChoise<=12);

do{
    printf("enter day(1-%d): ",maxday);
    scanf("%d",&monthChoise);

  }while(dayhChoise>=1&&dayhChoise<=maxday);

do{
    printf("enter day in week(1-%d): ",maxday);
    scanf("%d",&monthChoise);

  }while(dayhChoise>=1&&dayhChoise<=maxday);

  return 0;
}


int dayInWeek(int month,int day,int weekDay){




  
}