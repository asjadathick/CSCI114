/*
	File: solution2.cpp
	CSCI114 Mid Session Exam
	Author: Asjad Athick 4970512

	Desc:

	Prompts user to input alphanumeric chars A-z, regardless of case, using '.' to mark end of input.
	Then counts and displays the number of times A-G appeared in the sequence regardless of case
	
*/

#include <iostream>
using namespace std;

int main()
{
	char charBuffer;
	int charCount=0;
	bool invalidInput=false;

	cout<<"Enter characters from A-z, using a '.' to mark the end: " << endl;
	
	cin>>charBuffer;
	
	while (charBuffer!='.' && invalidInput==false)
	{
		//check if A-G regardless of case
		if ((charBuffer>='a' && charBuffer<='g') || (charBuffer>='A' && charBuffer<='G'))
		{
			//valid char, inc count
			charCount++;
		}

		if (!((charBuffer>='a' && charBuffer<='z') || (charBuffer>='A' && charBuffer<='Z')))
			invalidInput=true;

		cin>>charBuffer;
	}	

	if (invalidInput)
		cout<<"Invalid input. Only enter alphanumeric characters." << endl;
	else
		cout<<"Total number of characters from the first 7 letters of the alphabet contained in the input sequence is: " << charCount << endl;

	return 0;
}

