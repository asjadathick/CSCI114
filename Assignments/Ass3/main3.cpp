/*
Assignment 3
File: main3.cpp
Author: Asjad Athick 4970512
Dependency files: yahtzee.h/yahtzee.cpp

Desc:

Implementation of the game Yahtzee with one re-roll.
Also input safe.

*/

#include "yahtzee.h"

int main()
{
	//doesnt require re initialization
	int totalScore=0;
	int bonusCatScore=0;
	bool categories[13];
	bool successfulInput=true;

	for (int i=0; i<=13; i++)
	{
		categories[i]=false;
	}

	setSeed();

	//populate dice array with random numbers
	int i=0;
	while (i<=13 && successfulInput==true)
	{
		//initialization/declarations
		int diceValues[NUMBER_OF_DICE];
		int chosenCategory=0;
		initializeIntArray(diceValues,NUMBER_OF_DICE);

		int scores[13];
		initializeIntArray(scores,13);

		cout<<"Round " <<i<<endl;

		rollDice(diceValues);
		successfulInput= reRollDice(diceValues);
		
		if (successfulInput)
		{
			calculateScores(diceValues,scores);
			printProjectedScores(scores);
			chosenCategory=chooseCategory(categories);

		//update score according to chosen category
			recordAndPrintScore(chosenCategory,scores,totalScore,bonusCatScore);
		}
		else
		{
			cout<<"Invalid input: Program will terminate." << endl;
		}

		i++;
	}
	
	if (successfulInput)
	{

		if (bonusCatScore>62)
			totalScore+=bonusCatScore;

		cout<<"Your total score: " <<totalScore<<endl;
	}

	return 0;
}

