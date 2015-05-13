/*************************************************************************************
 * Filename:		solution2.cpp					   	     *
 * Lab:			4							     *
 * File Desc:		Accepts 4 characters as input (between 0-9) and puts them    *
			into one int						     *		     
 * Date Last Modified:	16 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	char ch1,ch2,ch3,ch4;
	bool error=false;
	int number=0;
	
	cout<<"Enter 4 single digit numbers: ";
	cin>>ch1>>ch2>>ch3>>ch4;

	if (!(ch1>=48 && ch1<=57))
	{
		error=true;
	}

	if (!(ch2>=48 && ch2<=57))
	{
		error=true;
	}

	if (!(ch3>=48 && ch3<=57))
	{
		error=true;
	}

	if (!(ch4>=48 && ch4<=57))
	{
		error=true;
	}

	if (error==true)
	{
		return 0;
	}else
	{
		number=((ch1-48) * 1000) + ((ch2-48) * 100) + ((ch3-48) * 10) + (ch4-48);
		cout << number<<endl;
		return 0;
	}

	
}
