/*************************************************************************************
 * Filename:		solution4.cpp					   	     *
 * Lab:			4							     *
 * File Desc:		Accepts a 4 digit number and outputs the highest digit and 
			the position of the digit				     *		     
 * Date Last Modified:	16 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	char n1=0,n2=0,n3=0,n4=0;
	int max=0;
	int index=0;
	
	cout<<"Enter 4 numbers: ";

	cin>>n1>>n2>>n3>>n4;

	//loop, but without a loop
	if (n1>max)
	{		
		max=n1;
		index=1;
	}

	if (n2>max)
	{		
		max=n2;
		index=2;
	}

	if (n3>max)
	{		
		max=n3;
		index=3;
	}

	if (n4>max)
	{		
		max=n4;
		index=4;
	}

	cout << "The largest digit is " << max-'0' << " at position " << index << "."<<endl;
	return 0;
}
