#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>


int printJoke(int coise);
int userChoice(void);



int main(void) {
  int a=0;
  a=userChoice();
  printJoke(a);
  return 0;
}


int printJoke(int coise){

//coise = userChoice();

  if(coise==1){
    printf("Knock, knock.\nWho’s there?\nTank.\nTank who?\nYou’re welcome.\n");
  }
  else if(coise==1){
    printf(" ");
  }
else if(coise==2){
    printf("Knock, knock.\nWho’s there?\nLuke.\nLuke who?\nLuke through the peep hole and find out.\n");
  }
else if(coise==3){
  printf("Knock, knock.\nWho’s there?\nFigs.\nFigs who?\nFigs the doorbell, it’s not working!\n");
  }
else if(coise==4){
    printf("Knock, knock.\nWho’s there?\nAnnie.\nAnnie who?\nAnnie thing you can do, I can do too!\n");
  }
else if(coise==5){
    printf("Knock, knock.\nWho’s there?\nCow says.\nCow says who?\nNo, a cow says mooooo!\n");
  }
else if(coise==6){
    printf("Knock, knock.\nWho’s there?\nHal.\nHal who?\nHal will you know if you don’t open the door?\n");
  }
else if(coise==7){
    printf("Knock, knock.\nWho’s there?\nAlice.\nAlice who?\nAlice fair in love and war.\n");
  }
else if(coise==8){
  printf("Knock, knock.\nWho’s there?\nSays.\nSays who?\nSays me!\n");
  }
else if(coise==9){
    printf("Knock, knock.\nWho’s there?\nHoney bee.\nHoney bee who?\nHoney bee a dear and get that for me please!\n");
  }
else if(coise==10){
    printf("Knock, knock.\nWho’s there?\nA little old lady.\nA little old lady who?\nHey, you can yodel!\n");
  }
else if(coise==11){
    printf("Knock, knock.\nWho’s there?\nEuripides.\nEuripides who?\nEuripides clothes, you pay for them!\n");
  }
else if(coise==12){
    printf("Knock, knock.\nWho’s there?\nSnow.\nSnow who?\nSnow use. The joke is over.\n");
  }
else if(coise==13){
    printf("Knock, knock.\nWho’s there?\nHawaii.\nHawaii who?\nI’m good. Hawaii you?\n");
  }
else if(coise==14){
    printf("Knock, knock.\nWho’s there?\nWoo.\nWoo who?\nGlad you’re excited, too!\n");
  }
else if(coise==15){
    printf("Knock, knock.\nWho’s there?\nBanana.\nBanana who?\nKnock, knock.\nBanana.\nBanana who?\nKnock, knock.\nWho’s there?\nOrange.\nOrange who?\nOrange you glad I didn’t say banana?\n");
  }
else if(coise==666){
    printf("no no\n");
    Sleep(1000);
    printf("what are you doing here?\n");
    Sleep(1000);
    printf("You're not supposed to be here\n");
    Sleep(1000);
    printf("please go\n");
    Sleep(3000);
    printf("Why are you still here?\n");
    Sleep(2000);
    printf("I'm serious GO!!\n");
    Sleep(1000);
    printf("I told you to go !!!\n");
    Sleep(2000);
    printf("If you do not leave for another 20 seconds I will have to use force?\n");
    Sleep(1000);
    printf("20\n");
    Sleep(1000);
    printf("19\n");
    Sleep(1000);
    printf("18\n");
    Sleep(1000);
    printf("17\n");
    Sleep(1000);
    printf("15\n");
    Sleep(1000);
    printf("14\n");
    Sleep(1);
    printf("13\n");
    Sleep(1000);
    printf("12\n");
    Sleep(1000);
    printf("11\n");
    Sleep(1000);
    printf("10\n");
    Sleep(1000);
    printf("9\n");
    Sleep(1000);
    printf("8\n");
    printf("7\n");
    Sleep(1000);
    printf("6\n");
    Sleep(1000);
    printf("5\n");
    Sleep(1000);
    printf("4\n");
    Sleep(1000);
    printf("3\n");
    Sleep(1000);
    printf("2\n");
    Sleep(1000);
    printf("1\n");
    Sleep(1000);
    while(1){
      printf("#");
    }
  }
 else{
	printf("EROR run egain");
	}
Sleep(1000000);
}



int userChoice(void){
  int coise=0;
  printf("print joke number: ");
  scanf("%d",&coise);
  return coise;
}