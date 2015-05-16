/*
	File name: solution3.cpp
	Lab 7
	Author: Asjad Athick 4970512
	
	Desc:
	Takes double interestRate, double initialInvestment, int years, and calculates 
	the value of the return
*/


#include <iostream>
using namespace std;

double invest (double interestRate, double initialInvestment, int years);

int main()
{
	double interestRate=0, initialInvestment=0;
	int years=0;

	double investment=0;

	cout << "Enter interest rate in decimals: " <<endl;
	cin >> interestRate;

	cout << "Enter initial investment value (AU$): " <<endl;
	cin>>initialInvestment;

	cout << "Enter number of years for investment: " <<endl;
	cin>>years;

	investment=invest(interestRate,initialInvestment,years);
	cout << "Your return will be: " << investment << " AU$" << endl;

	return 0;
}

double invest (double interestRate, double initialInvestment, int years)
{
	double investment=initialInvestment;

	for (int i=0; i<years; i++)
	{
		investment+=investment*(interestRate);
	}

	return (investment);

}