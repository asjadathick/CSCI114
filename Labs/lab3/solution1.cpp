/*************************************************************************************
 * Filename:		solution1.cpp					   	     *
 * Lab:			3							     *
 * File Desc:		Outputs last 3 digits of a number		             *		     
 * Date Last Modified:	2 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int five_digits = 12345; //initialize
	int three_digits=0;

	three_digits = five_digits % 1000; //compute
	
	//output
	cout << "The last three digits of a number " << five_digits << " are " << three_digits << "." << endl;

	return 0;
}
