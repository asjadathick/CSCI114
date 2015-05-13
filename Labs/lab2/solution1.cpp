/*************************************************************************************
 * Filename:		solution1.cpp						     *
 * Lab:			Week 4							     *
 * File Desc:		Outputs the sqaure and squareroot of a double type input i   *		     
 * Date Last Modified:	26 March 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main( int  argc, char** argv) 
{
	double i;
	cout <<"i = ";
	cin >> i;
	cout << pow(i, 2) <<"   "<< pow(i, 0.5) << endl; //outputs square and squareroot,
							 //using the pow function in <cmath> library
	return 0;
}
