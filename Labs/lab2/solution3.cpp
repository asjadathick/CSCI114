/*************************************************************************************
 * Filename:		solution3.cpp						     *
 * Lab:			Week 4							     *
 * File Desc:		Ouputs the Unit, Ten and Hundredth digit of a 3 digit integer* 				input			     				     *
 * Date Last Modified:	26 March 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int n = 985;
	int hundreds, tens, units; //replaced semicolon with comma in multiple variable declaration

	//compute the 3 values
	hundreds = n/100;
	tens = (n-hundreds*100)/10; //corrected spelling error in identifier name 'tens'
	units =(n-hundreds*100 - tens*10);

	cout <<"Hundreds " << hundreds << "\n";
	cout <<"Tens " << tens << "\n";
	cout <<"Units " << units << "\n"; 

	return 0; //corrected spelling error of 'return'
}
