/*************************************************************************************
 * Filename:		temperature.cpp						     *
 * Assignment:		2							     *
 * File Desc:		Converts farenheit temp to celsius and vice versa	     *
 * Date Last Modified:	2 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/
#include <iostream>
using namespace std;

int main()
{
	double temp=0;
	char unit='A';
	double convertedTemperature=0;
	
	//greeting
	cout<<"Enter a temperature followed by F for farenheit or C for Celsius"<<endl;
	
	//get input
	cin>>temp>>unit;

	//compute results
	if (unit =='F' || unit == 'f')
	{
		//if farenheit, use appropriate formula 
		convertedTemperature=((temp-32)*(5.0/9.0));
	}
	else if (unit =='C' || unit == 'c')
	{
		//if celsius, use appropriate formula
		convertedTemperature=((temp*(9.0/5.0))+32);
	}
	else
	{
		//if unit is invalid, output error
		cout<<"Invalid unit"<<endl;
	}
	

	//output value, with appropriate unit
	cout << temp << unit << " equals " << convertedTemperature << " in ";

	//decide which unit to output
	if (unit=='F' || unit =='f')
	{
		cout<<"C"<<endl;
	}
	else if (unit == 'C' || unit == 'c')
	{
		cout<<"F"<<endl;
	}

	return 0;
}
