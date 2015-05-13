/*************************************************************************************
 * Filename:		solution1.cpp
 * Lab:			5
 * File Desc:		Takes a date in mm dd yyyy format, and outputs the date in 				'March 15, 1987 Day 74', accounting leap years
 * Date Last Modified:	23 April 2015
 * Author:		Asjad Athick (4970512)
 ************************************************************************************/
#include <iostream>
using namespace std;

int main()
{
	int month=0;
	int date=0;
	int year=0;
	
	int m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,m7=0,m8=0,m9=0,m10=0,m11=0,m12=0;

	cout<<"Enter a date in mm dd yyyy format: "<<endl;
	cin>>month>>date>>year;

	switch (month)
	{
		case 1	:	cout<<"January";
				break;
		case 2	:	cout<<"February";
				break;
		case 3	:	cout<<"March";
				break;
		case 4	:	cout<<"April";
				break;
		case 5	:	cout<<"May";
				break;
		case 6	:	cout<<"June";
				break;
		case 7	:	cout<<"July";
				break;
		case 8	:	cout<<"August";
				break;
		case 9	:	cout<<"September";
				break;
		case 10	:	cout<<"October";
				break;
		case 11	:	cout<<"November";
				break;
		case 12	:	cout<<"December";
				break;
		default	:	cout<<"Invalid Month";
				break;
	}

	cout << " " << date << ", " << year;

	//calculate days
	//determine starting point of each month

	m2=31;

	//in case of leap year
	if (year%4==0)
	{
		if (year%100==0)
		{
			if (year%400==0)
			{
				m3=m2+29;
			}
			else
			{
				m3=m2+28;
			}
		}
		else
		{
			m3=m2+29;
		}
	}
	else
	{
	m3=m2+28;
	}
	
	
	m4=31+m3;
	m5=30+m4;
	m6=31+m5;
	m7=30+m6;
	m8=31+m7;
	m9=31+m8;
	m10=30+m9;
	m11=31+m10;
	m12=30+m11;
	
	//output number of days
	switch (month)
	{
		case 1	:	cout<<" Day " <<m1+date<<endl;
				break;
		case 2	:	cout<<" Day " <<m2+date<<endl;
				break;
		case 3	:	cout<<" Day " <<m3+date<<endl;
				break;
		case 4	:	cout<<" Day " <<m4+date<<endl;
				break;
		case 5	:	cout<<" Day " <<m5+date<<endl;
				break;
		case 6	:	cout<<" Day " <<m6+date<<endl;
				break;
		case 7	:	cout<<" Day " <<m7+date<<endl;
				break;
		case 8	:	cout<<" Day " <<m8+date<<endl;
				break;
		case 9	:	cout<<" Day " <<m9+date<<endl;
				break;
		case 10	:	cout<<" Day " <<m10+date<<endl;
				break;
		case 11	:	cout<<" Day " <<m11+date<<endl;
				break;
		case 12	:	cout<<" Day " <<m12+date<<endl;
				break;
	}


	return 0;
}
