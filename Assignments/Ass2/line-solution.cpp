/*************************************************************************************
 * Filename:		line-solution.cpp					     *
 * Assignment:		2							     *
 * File Desc:		Gives the equation of the line between 2 coordinates. 	     *
			Also confirms if another coordinate lies on that line	     *
 * Date Last Modified:	2 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main() 
{
	double x1 = 0, y1 = 0; 
	double x2 = 0, y2 = 0; 
	double x3 = 0, y3 = 0;
	double m = 0, b = 0;

	cout << "Enter the x y coordinates for point one (e.g. 0.5 1.7):";
	cin >> x1 >> y1;
	
	cout << "Enter the x y coordinates for point two: ";
	cin >> x2 >> y2; 	
	
	//Calculate slope and y-intercept
	m = (y2 - y1)/(x2 - x1); //slope = rise over run

	//line equation is y = m*x + b, so rearrange to get y-intercept b = m*x - y.
	//this is true for all points, so it must be true for x1 y1
	b = m*x1 - y1; //calculate y intercept
	
	cout << "Your two points lie on the line ";
	cout << "y = " << m << "x + " << b << endl;	
	
	//get a third point from user
	cout << "Enter the x y coordinates for point three:";
	cin >> x3 >> y3;

	//this will lie on the line if y3 = m*x3 + b
	if (y3 == ((m * x3) + b))
	{
		//point lies on line
		cout << "That point lies on the line" << endl;
	}
	else
	{
		//point does not lie on line
		cout << "That point does not lie on the line" << endl;
	}
	return 0;
}
