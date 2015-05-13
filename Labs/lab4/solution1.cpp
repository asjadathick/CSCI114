/*************************************************************************************
 * Filename:		solution1.cpp					   	     *
 * Lab:			4							     *
 * File Desc:		Outputs the largest number in a pair of 3 numbers from a text*
			file						             *		     
 * Date Last Modified:	16 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	float num1=0, num2=0;
	
	cin >> num1 >> num2;

	if (num1>num2)
	{
		cout<<num1<<endl;
	}else
	{
		cout <<num2<<endl;
	}
	
	cin >> num1 >> num2;

	if (num1>num2)
	{
		cout<<num1<<endl;
	}else
	{
		cout <<num2<<endl;
	}
	
	cin >> num1 >> num2;

	if (num1>num2)
	{
		cout<<num1<<endl;
	}else
	{
		cout <<num2<<endl;
	}

	return 0;
}
