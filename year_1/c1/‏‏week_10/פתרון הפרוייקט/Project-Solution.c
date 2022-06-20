/*********************************
* Class: MAGSHIMIM C1			 *
* Week 8           				 *
* Mastermind Project  			 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define FALSE 0					// Non-zero value used to symbol TRUE for boolean expressions
#define TRUE !0					// Zero value used to symbol FALSE for boolean expressions


enum difficultyLevel
{
	easy = 1,
	moderate,
	hard,
	crazy
};

// Global variables decelerations

// The four digits of the password
int passNum1 = 0;
int passNum2 = 0;
int passNum3 = 0;
int passNum4 = 0;


// Counter for number of tries
int numberOfTries = 0;	
// Flag indicates if we are in Crazy mode
int crazyFlag = 0;

// Constant definitions
const int	MIN_DIFFICULTY = 1;			// Minimal difficulty option for the game
const int	MAX_DIFFICULTY = 4;			// Maximal difficulty option for the game

const int	EASY_NUM_ROUNDS = 20;		// Number of guesses the player has when playing the easy level
const int	MODERATE_NUM_ROUNDS = 15;	// Number of guesses the player has when playing the moderate level
const int	HARD_NUM_ROUNDS = 10;		// Number of guesses the player has when playing the hard level
const int	CRAZY_NUM_ROUNDS_MIN = 5;	// Minimal number of guesses the player has when playing the crazy level
const int 	CRAZY_NUM_ROUNDS_MAX = 25; 	// Maximal number of guesses the player has when playing the crazy level

const int	MIN_SIGN = '1';		// Minimal ASCII value of a password digit
const int	MAX_SIGN = '6';		// Maximal ASCII value of a password digit

const int 	VICTORY_HITS = 4; 	// Number of hits needed to win

const char	BIG_YES = 'Y';
const char 	SMALL_YES = 'y';
const char	BIG_NO = 'N';
const char 	SMALL_NO = 'n';



// Functions deceleration
void displayRules(void);
enum difficultyLevel getDifficulty(void);
int getNumberOfRounds(enum difficultyLevel diff); 
int playGame(int numRounds); 
void createPassword(void); 

int checkInput(int guess1, int guess2, int guess3, int guess4); //check inputChar hits and misses. returns TRUE in case of 4 hits. any other case, returns FALSE.
int validYesNoReply(char ans);


int main(void)
{
	// Variable definition
	int anotherGame = FALSE; // Flag indicating whether the user selected to continue
	enum difficultyLevel diff = 0;
	int numRounds = 0;
	int gameResult = FALSE;
	
	// Init the random generator
	srand(time(NULL));
	
	do //Game loop
	{
		crazyFlag = 0;
		displayRules();
		diff = getDifficulty();
		numRounds = getNumberOfRounds(diff);
		gameResult = playGame(numRounds);
		if(gameResult)
		{
			printf("\nIt took you only %d guesses, you are a professional code breaker!\n", numberOfTries);
		}
		else
		{
			printf("\nOOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts.\nNothing left for you... \nThe secret password was %1d%1d%1d%1d\n",passNum1,passNum2,passNum3,passNum4);
		}
		
		anotherGame = playAgain();
			
	} while (anotherGame);
	printf("\n\nBye Bye!\n");
	system("PAUSE");
	return 0;
}

/*
Function displays rules of game to screen.
input: none
output: none
*/
void displayRules(void)
{
	// Welcome message
	printf("\nWelcome to \"MAGSHIMIM CODE-BREAKER\"!!!\n\n");
	printf("A secret password was chosen to protect the credit card of Pancratius,\nthe descendant of Antiochus.\n");
	printf("Your mission is to stop Pancratius by revealing his secret password.\n\n");
	printf("The rules are as follows:\n");
	printf("1. In each round you try to guess the secret password (4 distinct digits)\n");
	printf("2. After every guess you'll receive two hints about the password\n");
	printf("   HITS:   The number of digits in your guess which were exactly right.\n");
	printf("   MISSES: The number of digits in your guess which belongs to\n");
	printf("           the password but were miss-placed.\n");
	printf("3. If you'll fail to guess the password after a certain number of rounds\n");
	printf("   Pancratius will buy all the gifts for Hanukkah!!!\n\n");
}

/*
Displays menu to the screen and options for the game. 
input: none
output: user's selected difficulty level
*/
enum difficultyLevel getDifficulty(void)
{	
	//Variables
	enum difficultyLevel difficulty = 0;// Game difficulty level
	int scanfSuccesses = 0;
		
	// Ask player to enter a difficulty level
	printf("Please choose the game level:\n");
	printf("%d - Easy (%d rounds)\n", easy, EASY_NUM_ROUNDS);
	printf("%d - Moderate (%d rounds)\n", moderate, MODERATE_NUM_ROUNDS);
	printf("%d - Hard (%d rounds)\n", hard, HARD_NUM_ROUNDS);
	printf("%d - Crazy (random number of rounds %d-%d)\n", crazy, CRAZY_NUM_ROUNDS_MIN, CRAZY_NUM_ROUNDS_MAX);	
	do
	{
		printf("Make a choice: ");
		scanfSuccesses = scanf("%d", &difficulty);
		getchar(); // clean buffer
	}
	while (difficulty < MIN_DIFFICULTY || difficulty > MAX_DIFFICULTY || scanfSuccesses == 0); 
	// Check if the selected option is valid
	// Initialize the number of rounds based on user choice for difficulty level
	return difficulty;
}

/*
Function will return number of rounds for a certain difficulty level.
input: the difficulty level
output: number of rounds for this game
*/
int getNumberOfRounds(enum difficultyLevel diff)
{
	// Variables definitions
	int numRounds = 0;
	switch(diff)
	{
		case(easy):
			numRounds = EASY_NUM_ROUNDS;
			break;
		case(moderate):
			numRounds = MODERATE_NUM_ROUNDS;
			break;
		case(hard):
			numRounds = HARD_NUM_ROUNDS;
			break;
		default: 
			numRounds = rand() % (CRAZY_NUM_ROUNDS_MAX - CRAZY_NUM_ROUNDS_MIN + 1) + CRAZY_NUM_ROUNDS_MIN;
			crazyFlag = TRUE;
			break;
	}
	return numRounds;
}

/*
Function will create a random password according to the rules
input: none
output: none
*/
void createPassword(void)
{
	const int	SIGNS_RANGE_SIZE = MAX_SIGN - MIN_SIGN + 1; // Number of options of every digit (used for randomization)

	// Draw first digit. There are no limitations on the first digit.
	passNum1 = rand() % SIGNS_RANGE_SIZE + 1;
	
	// Draw second digit. To prevent duplicates compare to first digit.
	do
	{ 
		passNum2 = rand() % SIGNS_RANGE_SIZE + 1;
	}
	while (passNum1 == passNum2);
	
	// Draw third digit. To prevent duplicates compare to first 2 digits.
	do
	{ 
		passNum3 = rand() % SIGNS_RANGE_SIZE + 1;
	}
	while (passNum1 == passNum3 || passNum2 == passNum3);
	
	// Draw fourth digit. To prevent duplicates compare to first 3 digits.
	do
	{
		passNum4 = rand() % SIGNS_RANGE_SIZE + 1;
	}
	while (passNum1 == passNum4 || passNum2 == passNum4 || passNum3 == passNum4);
}

/*
Main game function.
input: number of rounds to play
output: TRUE for victory, FALSE for loss
*/
int playGame(int numRounds) 
{	
	// Constant definitions
	const int	REF_SIGN = '0';				// A reference ASCII value used to convert char-digits into int-digits
	const int	SIGNS_RANGE_SIZE = MAX_SIGN - MIN_SIGN + 1; // Number of options of every digit (used for randomization)
						
	//Variables definitions
	int hit = 0;							// Number of HITS (exactly-right guesses) in a single round
	int miss = 0; 							// Number of MISSES (digit is in the password, but miss-placed) in a single round	
	int badInput = FALSE;					// Flag indicating if the user has entered a bad input
	int retValue = FALSE;
	int winFlag = FALSE;

	char guess1 = ' ';
	char guess2 = ' ';
	char guess3 = ' ';
	char guess4 = ' '; 				// Four digits guessed by the user

	createPassword();
	for (numberOfTries = 0 ; numberOfTries < numRounds && !winFlag ; numberOfTries++)
	{
		// Reset the flag which symbols bad input of the user
		badInput = FALSE;
		// Get the user guess and check that every digit is valid
		printf("Write your guess (only %d-%d, no ENTER is needed) \n", MIN_SIGN - REF_SIGN, MAX_SIGN - REF_SIGN);
		crazyFlag ? printf("CRAZY MODE!!!\n") : printf("%d guesses left\n", numRounds-numberOfTries);
		
		guess1 = getch();
		printf("%c",guess1);
		if(guess1 < MIN_SIGN || guess1 > MAX_SIGN)
		{
			badInput = TRUE;
		}
		guess2 = getch();
		printf("%c",guess2);
		if(guess2 < MIN_SIGN || guess2 > MAX_SIGN)
		{
			badInput = TRUE;
		}
		guess3 = getch();
		printf("%c",guess3);
		if(guess3 < MIN_SIGN || guess3 > MAX_SIGN)
		{
			badInput = TRUE;
		}
		guess4 = getch();
		printf("%c",guess4);
		if(guess4 < MIN_SIGN || guess4 > MAX_SIGN)
		{
			badInput = TRUE;
		}
	
		if(!badInput)
		{
			winFlag = checkInput((int)guess1, (int)guess2, (int)guess3, (int)guess4);
		}
		else
		{
			printf("\nOnly %d-%d are allowed, try again!\n", MIN_SIGN - REF_SIGN, MAX_SIGN - REF_SIGN);
			numberOfTries--; // Since the user didn't guess, discard the current round from the number of played rounds
		}
	} // end Round-Loop: for (numberOfTries = 0 ; numberOfTries < numRounds && !winFlag ; numberOfTries++)
	
	return winFlag;
}

/*
Function checks number of hits and misses
input: the user guesses
output: TRUE for win (4 hits). FALSE otherwise
*/
int checkInput(int guess1, int guess2, int guess3, int guess4) 
{
	// Constant definitions
	const char	REF_SIGN = '0'; // A reference ASCII value used to convert char-digits into int-digits

	int retValue = FALSE;
	int hit = 0;
	int miss = 0;
	// Convert user guesses from chars numbers (integers)
	guess1 -= REF_SIGN;
	guess2 -= REF_SIGN;
	guess3 -= REF_SIGN;
	guess4 -= REF_SIGN;
	
	// Calculate the number of HITS and MISSES.
	if (guess1 == passNum1)
	{
		hit++;
	}
	else if (guess1 == passNum2 || guess1 == passNum3 || guess1 == passNum4)
	{
		miss++;
	}
	if (guess2 == passNum2)
	{
		hit++;
	}
	else if (guess2 == passNum1 || guess2 == passNum3 || guess2 == passNum4)
	{
		miss++;
	}
	if (guess3 == passNum3)
	{
		hit++;
	}
	else if (guess3 == passNum1 || guess3 == passNum2 || guess3 == passNum4)
	{
		miss++;
	}
	if (guess4 == passNum4)
	{
		hit++;
	}
	else if (guess4 == passNum1 || guess4 == passNum2 || guess4 == passNum3)
	{
		miss++;
	}
	if (hit == VICTORY_HITS)
	{
		printf("\n%4d HITS YOU WON!!!\n", hit);
		retValue = TRUE;
	}
	else
	{
		printf("\nYou got %4d HITS %4d MISSES.\n", hit, miss);
	}
	return retValue;
}

/*
Ask the user if he'd like to play again and get his answer. 
input: none
output: TRUE if the user wants to play again. FALSE otherwise.
*/
int playAgain(void)
{
	char anotherGame = 0;
	do
	{
		printf("\nWould you like to play again? (y/n): ");
		anotherGame = getch();
		putchar(anotherGame);
	} while (!validYesNoReply(anotherGame));
	return (anotherGame == BIG_YES || anotherGame == SMALL_YES);
}

/*
Function validates whether an answer is a yes or no
input: the char answer
output: TRUE if it's a yes or no char answer
*/
int validYesNoReply(char ans)
{
	return (ans == BIG_YES || ans == SMALL_YES || ans == BIG_NO || ans == SMALL_NO);
}
