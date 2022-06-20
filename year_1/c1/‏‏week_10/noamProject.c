#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

enum difficult {easy=1, medume, hard, extrame};

int startProgram();
int returnRandoms(int lower, int upper);
//srand(time(NULL));
int createNewRandomSecretCode();
int guesses();
int guessTest(int guesses1,int guesses2,int guesses3,int guesses4);
int gameOver();
int victory();


int firstCode=0, secondCode=0, thirdCode=0, fourtCode=0;
int remainingGuesses =0;
bool isHard = 0;


int main(void) {
	startProgram();

}

//קולטתומהמשתמש רמת קושי ןקוראת ל"ניחושים"
int startProgram(){
	enum difficult difficulty;
	createNewRandomSecretCode();
	printf("Welcome to MAGSHIMIM CODE-BREAKER!!!\n\n");
  	printf("A secret password was chosen to protect the credit card of Pancratius,\n");
  	printf("the descendant of Antiochus.\n");
  	printf("Your mission is to stop Pancratius by revealing his secret password.\n\n");
  	printf("The rules are as follows:\n");
  	printf("1. In each round you try to guess the secret password (4 distinct digits)\n");
	printf("2. After every guess you'll receive two hints about the password\n");
	printf("   HITS:   The number of digits in your guess which were exactly right.\n");
	printf("   MISSES: The number of digits in your guess which belongs to\n");
	printf("     the password but were miss-placed.\n");
	printf("3. If you'll fail to guess the password after a certain number of rounds\n");
	printf("   Pancratius will buy all the gifts for Hanukkah!!!\n\n");
	printf("   Please choose the game level:\n");
	printf("1 - Easy (20 rounds)\n");
	printf("2 - Moderate (15 rounds)\n");
	printf("3 - Hard (10 rounds)\n");
	printf("4 - Crazy (random number of rounds 5-25)\n\n");
	remainingGuesses=0;
	while(remainingGuesses==0){
		printf("Make a choice:");
		scanf("%d",&difficulty);

	switch (difficulty){
    case 1:
      remainingGuesses = 20;
	  isHard = 0;
      break;

    case 2:
    remainingGuesses = 15;
    isHard = 0;
      break;
	  
    case 3:
    remainingGuesses = 10;
    isHard = 0;
      break;
	  
    case 4:
	//srand(time(NULL));
    remainingGuesses = returnRandoms(5,25);
    isHard = 1;
      break;
	  
    default:
     printf("ERROR try again\n");
}

	}
  guesses();
}

//מחזיר מספר רנדומלי
int returnRandoms(int lower, int upper)
{
  int num = (rand() % (upper - lower + 1)) + lower;
  return num;
    
}

//יוצר מספר סודי רנדומלי
int createNewRandomSecretCode(){
	srand(time(NULL));
	firstCode = returnRandoms(1,6);
	
  do{
    secondCode = returnRandoms(1,6);
  }while(secondCode == firstCode);
  do{
    thirdCode = returnRandoms(1,6);
  }while(thirdCode == firstCode || thirdCode == secondCode);
  do{
    fourtCode = returnRandoms(1,6);
  }while(fourtCode == firstCode || fourtCode == secondCode || fourtCode == thirdCode);
  printf("the ran code is %d%d%d%d\n",firstCode, secondCode, thirdCode, fourtCode);
}


//קולט ניחושים ומעבירה אותם לבדיקה
int guesses(){
  int guesses1, guesses2, guesses3, guesses4;
  while(remainingGuesses != 0){
	printf("Write your guess (only 1-6, no ENTER is needed)\n");
if(isHard != 1){
	printf("%d guesses left\n",remainingGuesses);
}
  guesses1=getch()-48;
  printf("%d",guesses1);
  guesses2=getch()-48;
  printf("%d",guesses2);
  guesses3=getch()-48;
  printf("%d",guesses3);
  guesses4=getch()-48;
  printf("%d",guesses4);
  guessTest(guesses1,guesses2,guesses3,guesses4);
  remainingGuesses-=1;
  }
	gameOver();
}

//בודק ניחושים ומדפיס תוצאה
int guessTest(int guesses1,int guesses2,int guesses3,int guesses4){
	int prefect=0, about=0;
	if(guesses1==firstCode)
		prefect++;
	else if(guesses1==secondCode||guesses1==thirdCode||guesses1==fourtCode)
		about++;
	
	if(guesses2==secondCode)
		prefect++;
	else if(guesses2==firstCode||guesses2==thirdCode||guesses2==fourtCode)
		about++	;
	
	if(guesses3==thirdCode)
		prefect++;
	else if(guesses3==firstCode||guesses3==secondCode||guesses3==fourtCode)
		about++	;
	if(guesses4==fourtCode)
		prefect++;
	else if(guesses4==firstCode||guesses4==secondCode||guesses4==thirdCode)
		about++;
	printf("\nYou got    %d HITS    %d MISSES\n",prefect,about);
	
	if(prefect==4){
	victory();
	//remainingGuesses =0;
	}
}


//מדפיס הודעת הפסד
int gameOver(){
	getchar();
	printf("loser\n do you want to start again(y/n)?");
    char replay=' ';
    scanf("%c",&replay);
  if (replay=='y')
  startProgram();
}
//מדפיס הודעת ניצחון
int victory(){
	getchar();
	printf("victory\n do you want to start again(y/n)?");
    char replay=' ';
    scanf("%c",&replay);
  if (replay=='y')
  startProgram();
}