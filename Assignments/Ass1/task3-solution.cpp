/*************************************************************************************
 * Filename:		task3-solution.cpp					     *
 * Assignment:		1							     *
 * File Desc:		Finds the distance between two coordinates using a cartesian *
			equation.						     *
 * Date Last Modified:	26 March 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

/* Changes Made:
1) Corrected variable names in the cin input sequence to assign input to proper 
   variables
2) Corrected the cartesian equation to find the distance between 2 coordinates
3) Declared the identifier distance, as a double
4) Corrected case of 'Distance' to distance in last cout statement
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x1, y1;
    double x2, y2;
    double distance;
    
    cout << "Enter x coordinate of the first point= ";
    cin >> x1;

    cout << "Enter y coordinate of the first point= ";
    cin >> y1;

    cout << "Enter x coordinate of the second point= ";
    cin >> x1;

    cout << "Enter y coordinate of the second point= ";
    cin >> y1;
    
    distance = sqrt(((x2 - x1) * ( x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    
    cout << "Distance = " << distance << endl;
    return 0;
}

