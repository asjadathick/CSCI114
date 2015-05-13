/*************************************************************************************
 * Filename:		task2-solution.cpp					     *
 * Assignment:		1							     *
 * File Desc:		Draws a diamond of the height input			     *
 * Date Last Modified:	26 March 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int height;

	cout << "Enter the Height (odd positive numbers only): "<< endl; 
	cin >> height; 

	for( int y=0; y < height; y++ )
	{
		for( int x=0; x < height; x++ )
		{
			int X = abs( x - ( height / 2 ) ); 
			int Y = abs( y - ( height / 2 ) );
			if( ( X + Y ) <= ( height / 2 ) )
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}	
		} 
		cout << endl;
	}
	return 0;
}


