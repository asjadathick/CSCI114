/*
	File: solution3.cpp
	CSCI114 Mid Session Exam
	Author: Asjad Athick 4970512

	Desc:

	Prompts user to input two integer sequences consisting of integers from 2-9, ending with -1
	Terminates (without breaks) if invalid sequence. Prints in ascending the numbers that neither
	sequence contained.
*/

#include <iostream>
using namespace std;

int main()
{
	bool numbersSeen[7]; //0 - 6 index represent numbers 2-9
	int numBuffer=0;
	bool invalidSequence=false;
	
	cout<<"Enter two sequences of integers: 2-9, using -1 to mark the end of each sequence: " << endl;
	//input sequence
	for (int i=0; i<2; i++)
	{
		cin>>numBuffer;
		while (numBuffer!=-1 && invalidSequence==false)
		{
			//check if valid
			if (numBuffer>=2 && numBuffer<=9)
			{
				//valid
				numbersSeen[numBuffer-2]=true;
				cin>>numBuffer;
			}
			else
			{
				invalidSequence=true;
			}
		}		
	}

	//output whats false
	if (invalidSequence==true)
	{
		cout << "Invalid sequence" << endl;
	}
	else
	{
		for (int i=0; i<8; i++)
		{
			if (numbersSeen[i]==false)
				cout<< (i+2) << " ";
		}

		cout<<endl;
	}
	

	return 0;
}
