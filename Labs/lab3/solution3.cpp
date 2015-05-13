/*************************************************************************************
 * Filename:		solution3.cpp					   	     *
 * Lab:			3							     *
 * File Desc:		Converts length in feet and inces to meteres and centimeters *		     
 * Date Last Modified:	2 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double feet = 7, inches = 3;
	double centimeter = 0;
	int meter = 0;

	inches = inches + (feet * 12); //compute feet to inches
	centimeter = inches * 2.54;

	meter = centimeter / 100; //get total meters
	centimeter = centimeter - (meter * 100); //get remaining cm, preserving the decimal (i.e not using mod)

	cout << "A length of " << feet << " feet and " << inches << " inches is equal to " << meter << " metres and " << centimeter << " centimetres." << endl;

	return 0;

}
