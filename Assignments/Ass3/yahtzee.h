#include <iostream>
#include <iomanip>

using namespace std;

const int NUMBER_OF_DICE = 5;
const char SCORE_CATEGORIES[13][30]=
	{
		{"Aces"},
		{"Twos"},
		{"Threes"},
		{"Fours"},
		{"Fives"},
		{"Sixes"},
		{"3 of a kind"},
		{"4 of a kind"},
		{"Full House"},
		{"Small Straight"},
		{"Large Straight"},
		{"Yahtzee"},
		{"Chance"}
	};

//program method prototypes
void setSeed();
void rollDice(int diceValues[]);
bool reRollDice(int diceValues[]);
void calculateScores(int input[], int scores[]);
void printProjectedScores(int scores[]);
int chooseCategory(bool categories[]);
void recordAndPrintScore(int chosenCategory, int scores[], int& totalScore, int& bonusCatScore);

//score calculating method prototypes
void firstSix(int input[], int scores[]);
int ofaKind(int input[], int kind);
int fullHouse(int input[]);
int smallStraight(int input[]);
int largeStraight(int input[]);
int yahtzee(int input[]);
int chance(int input[]);

//utility method prototypes
void initializeIntArray(int array[],int upperBound);
int sumOfArray(int array[], int upperBound);
void copyArray(int toArray[], int fromArray[], int upperBound);
void sortArray(int array[], int ARRAY_SIZE);
void outputArray(int array[], int upperBound);
void emptyStream();
