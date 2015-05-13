/*************************************************************************************
 * Filename:		solution4.cpp
 * Lab:			5
 * File Desc:		Counts the number of lines, chars, words in a input stream. 				Gives correct amount of words even if multiple delimitters are 				used
 * Date Last Modified:	23 April 2015
 * Author:		Asjad Athick (4970512)
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{

	bool delimitFlag=false;
	int chars=0, words=0, lines=0;
	char compValue;

	//analyze each char
	
	do
	{
		//keep doing until EOF is simulated 

		compValue=cin.get();
		if ((compValue==' ') || (compValue=='\t') || (compValue=='\n'))
		{
			//if delimitter is detected
			if (delimitFlag==false)
			{
				//if its not a recurring delimitter
				//acutal space
				delimitFlag=true;
				words++;
				chars++;
			}
		}
		else
		{
			//turn off flag whenever a non delimitter is encountered
			delimitFlag=false;
			chars++;
		}

		if (compValue=='\n')
		{
			lines++; // n of lines
		}

	}
	while (!(cin.fail()));
	
	cout<<"Characters: " << chars << " Lines: " << lines << " Words: " <<words <<endl;
	
}
