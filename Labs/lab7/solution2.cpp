/*
	File name: solution2.cpp
	Lab 7
	Author: Asjad Athick 4970512
	
	Desc:
	Takes 3 doubles as input: a,b,c. Shifts/rotates values of a,b,c to the right
*/

#include <iostream>
using namespace std;

void rotate(double& a, double& b, double& c);

int main()
{
	double n1=0, n2=0, n3=0;
	cout<<"Enter three real numbers to rotate: " <<endl;
	cin>>n1>>n2>>n3;
	rotate(n1,n2,n3);
	cout<<"A: " << n1 << " B: " << n2 << " C: " << n3 << endl;

	return 0;
}

void rotate(double& a, double& b, double& c)
{
	double tempforB=0, tempforC=0;

	tempforB=b;
	tempforC=c;

	b=a;
	c=tempforB;
	a=tempforC;

}