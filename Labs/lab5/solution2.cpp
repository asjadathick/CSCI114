/*************************************************************************************
 * Filename:		solution2.cpp
 * Lab:			5
 * File Desc:		Formats a number (max 7 digits) with commas Ex 1000 -> 1,000
 * Date Last Modified:	23 April 2015
 * Author:		Asjad Athick (4970512)
 ************************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int input=0;
	int compareValue=0;
	int divisor=1000000;
	bool outputFlag=false;

	cout<<"Enter a number (7 digits max)"<<endl;
	cin>>input;

	compareValue=(input/divisor);

	if (compareValue!=0)
	{
		cout<<"Formatted: "<<compareValue<<",";
		outputFlag=true;
	}

	while (divisor>100)
	{
		divisor/=1000;
		compareValue=(input/divisor);
		//cout<<"comp:"<<compareValue;
		compareValue%=1000;
		if (compareValue!=0)
		{
			if (outputFlag==true) //output flag decides if the output must be padded with 0, by looking at if an output is already made
			{
				cout<<setw(3)<<setfill('0')<<compareValue;
			}
			else
			{
				cout<<compareValue;
				outputFlag=true; //as first output is made, set flag
			}
				
			//check if last set of digits to put comma
			if (divisor>100)
			{
				cout<<","; //dont put comma if last set
			}
		}
	}
	
	cout<<endl;
	return 0;

	 
}
