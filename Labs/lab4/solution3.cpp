/*************************************************************************************
 * Filename:		solution3.cpp					   	     *
 * Lab:			4							     *
 * File Desc:		Displays 5 real numbers in different formats		     *		     
 * Date Last Modified:	16 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double n1=0,n2=0,n3=0,n4=0,n5=0;
	cin>>n1>>n2>>n3>>n4>>n5;
	
	//one position point after decimal
	cout<<setprecision(1)<<showpoint<<fixed<<n1<<endl<<n2<<endl<<n3<<endl<<n4<<endl<<n5<<endl;
	
	//six position points after decimal
	
	cout<<setprecision(6)<<showpoint<<fixed<<n1<<endl<<n2<<endl<<n3<<endl<<n4<<endl<<n5<<endl;

	//round off to whole integer
	cout<<setprecision(0)<<resetiosflags(ios::showpoint)<<fixed<<n1<<endl<<n2<<endl<<n3<<endl<<n4<<endl<<n5<<endl;

	//right justified in 10 spaces
	cout<<setw(10)<<right<<n1<<endl;
	cout<<setw(10)<<right<<n2<<endl;
	cout<<setw(10)<<right<<n3<<endl;
	cout<<setw(10)<<right<<n4<<endl;
	cout<<setw(10)<<right<<n5<<endl;

	//left justified in 10 spaces
	cout<<setw(10)<<left<<n1<<endl;
	cout<<setw(10)<<left<<n2<<endl;
	cout<<setw(10)<<left<<n3<<endl;
	cout<<setw(10)<<left<<n4<<endl;
	cout<<setw(10)<<left<<n5<<endl;

	return 0;
}
