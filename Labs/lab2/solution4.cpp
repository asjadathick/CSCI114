/*************************************************************************************
 * Filename:		solution4.cpp						     *
 * Lab:			Week 4							     *
 * File Desc:		Takes in x,y,z as input. Computes the result according to    *
 *			the expression x * (y /(z+1))				     *
 * Date Last Modified:	26 March 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double x, y, z, result; //variable type changed to double to work with decimals
	
        cout <<"Enter a value of x and press Enter key" << endl;
        cin >> x;

        cout <<"Enter a value of y and press Enter key" << endl;
        cin >> y;

        cout <<"Enter a value of z and press Enter key" << endl;
        cin >> z;

	result = x * (y /(z+1)); //brackets added to enforce order of operations

	cout << "A value of x * (y /(z+1)) equals to " << result << endl;
	cout << "Have a nice day." << endl;

	return 0;
}

