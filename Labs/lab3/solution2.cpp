/*************************************************************************************
 * Filename:		solution2.cpp					   	     *
 * Lab:			3							     *
 * File Desc:		Converts weight in pounds and ounces to kg	             *		     
 * Date Last Modified:	2 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double pounds = 5 , kilograms = 0; //initialization
	int ounces = 3; //because mod function takes just ints
	
	pounds = pounds + ounces/16.0; //.0 because decimal portion is significant for computation
	ounces = ounces % 16;
	kilograms = pounds / 2.2046;

	cout << "A weight of " << pounds << " pounds and " << ounces << " ounces is equal to " << kilograms << " kilograms."<< endl;

	return 0;
}
