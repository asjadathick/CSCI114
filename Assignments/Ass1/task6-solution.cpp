/*************************************************************************************
 * Filename:		task6-solution.cpp					     *
 * Assignment:		1							     *
 * File Desc:		Adds up two times in HHMM format, to give total time in      *
			d HHMM format						     *
 * Date Last Modified:	26 March 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int HH1, HH2, MM1, MM2;
	int d, HH, MM;
	
	//input variables

	HH1=10; //hour of time1
	MM1=30; //minute of time1
	HH2=20; //hour of time2
	MM2=13; //minute of time2

	//computing final time
	HH=(MM1+MM2)/60; //overflow minutes in hours
	MM=(MM1+MM2)%60; //remaining minutes

	HH=HH+(HH1+HH2); //total hours
	d=HH/24; //overflow hours in days
	HH=HH%24; //remaining hours
	

	//output method
	cout<<d<<" ";

	if (HH<10){
		cout<<"0"; //if int is single digit, extra 0 is printed
	}

	cout<<HH;

	if (MM<10){
		cout<<"0"; //if int is single digit, extra 0 is printed
	}

	cout<<MM<<endl;
}
