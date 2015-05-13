/*************************************************************************************
 * Filename:		solution3.cpp
 * Lab:			5
 * File Desc:		Calculates the standard deviation of a set of integers
 * Date Last Modified:	23 April 2015
 * Author:		Asjad Athick (4970512)
 ************************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double sum=0;
	double sumOfSquares=0;
	double n=0;
	double average=0;
	int value=0;
	double stdDeviation=0;

	cout<<"Enter positive integers (negative integer to terminate): "<<endl;
	cin>>value;
	while (value>0)
	{
		//keeps going until a sentinal (neg num) in enterred 
		cout<<value<<endl;
		sum+=value;
		sumOfSquares+=(value*value);
		n++;
		cin>>value;
	}

	average=sum/n;


	//calculate std deviation
	stdDeviation=sqrt((sumOfSquares/n)-(average*average));
	cout<<"Standard Deviation: " << stdDeviation << endl;
	return 0;
}
