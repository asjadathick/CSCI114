/*
	File name: solution1.cpp
	Lab 7
	Author: Asjad Athick 4970512
	
	Desc:
	Takes 2 nums as input and returns if either number is a multiple of the other
	Also input safe 
*/

#include <iostream>
using namespace std;

bool multiple(int m, int n);

int main()
{
	int n1=0, n2=0;
	int isMultiple=false;

	cout<<"Enter two integers: " <<endl;
	cin>>n1>>n2;

	if (!cin.good())
		cout<<"Invalid Input, enter only ints"<<endl;
	else
	{
		isMultiple=multiple(n1,n2);
		if (isMultiple)
			cout<<"Numbers are multiples"<<endl;
		else
			cout<<"Numbers are not multiples"<<endl;

	}

	return 0;
}

bool multiple(int m, int n)
{
	bool result=false;

	if (m % n==0)
		result=true;

	if(n % m==0)
		result=true;

	return result;
}