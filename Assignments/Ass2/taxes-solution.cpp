/*************************************************************************************
 * Filename:		taxes-solution.cpp					     *
 * Assignment:		2							     *
 * File Desc:		Calculates the income tax due for a person based on	     *	
			their annual income, accounting Residency/Non Residency	     *
			status, and using the appropriate tax rates		     *
 * Date Last Modified:	2 April 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char response='a';
	int income=0;
	double tax=0;

	//get residency status
	cout << "Are you an Australian resident(y/n)? ";
	cin >> response;

	//display appropriate tax rates
	if (response == 'y' || response == 'Y')
	{
		//rates if resident
		cout << "Resident tax rates" << endl
		<<  left << setw(25) <<"0 - $18,200"
		<<  left << setw(25) <<"Nil" << endl
		<<  left << setw(25) <<"$18,201 - $37,000"
		<<  left << setw(25) <<"19c for each $1 over $18,200" << endl
		<<  left << setw(25) <<"$37,001 - $80,000"
		<<  left << setw(25) <<"$3,572 plus 32.5c for each $1 over $37,000" << endl
		<<  left << setw(25) <<"$80,001 - $180,000"
		<<  left << setw(25) <<"$17,547 plus 37c for each $1 over $80,000" << endl
		<<  left << setw(25) <<"$180,001 and over"
		<<  left << setw(25) <<"$54,547 plus 45c for each $1 over $180,000"<<endl;
	}
	else if (response == 'n' || response =='N')
	{
		//rates if non resident
		cout << "Non-resident tax rates" << endl
		<< left << setw(25) << "0 - $80,000"
		<< left << setw(25) << "32.5c for each $1" << endl
		<< left << setw(25) << "$80,001 - $180,000"
		<< left << setw(25) << "$26,000 plus 37c for each $1 over $80,000" << endl
		<< left << setw(25) << "$180,001 and over"
		<< left << setw(25) << "$63,000 plus 45c for each $1 over $180,000"<<endl;
	}
	else
	{
		//display error message if invalid response 
		cout << "Invalid repsonse." << endl;
		return 1;
	}	
	
	//get income
	cout << endl <<"Please enter your income over the past financial year in whole dollars: ";
	cin >> income ;
	
	//calculate tax
	if (response == 'y' || response == 'Y')
	{
		//if resident

		if (income>=0 && income<=18200)
		{
			cout << "Your income tax is Nill";
		}
		else if (income>=18201 && income <=37000)
		{
			tax = (.19 * (income - 18200));
			cout << fixed << setprecision(2) << "Your income tax is " << tax;
		}
		else if (income>=37001 && income<=80000)
		{
			tax = (3572 + (.352 * (income - 37000)));
			cout << fixed << setprecision(2) << "Your income tax is " << tax;
		}
		else if (income>=80000 && income <=180000)
		{
			tax = (17547 + (.37 * (income - 80000)));
			cout << fixed << setprecision(2) << "Your income tax is " << tax;
		}
		else if (income>=180001)
		{
			tax = (54547 + (.45 * (income - 180000)));
			cout << fixed << setprecision(2) << "Your income tax is " << tax;
		}
	}
	else
	{
		//if non resident

		if (income>=0 && income<=80000)
		{
			tax = (.325 * (income - 0));
			cout << fixed << setprecision(2) << "Your income tax is " << tax;
		}
		else if (income>=80001 && income <=180000)
		{
			tax = (26000 + (.37 * (income - 80000)));
			cout << fixed << setprecision(2) << "Your income tax is " << tax;
		}
		else if (income>=180001)
		{
			tax = (63000 + (.45 * (income - 18000)));
			cout << fixed << setprecision(2) << "Your income tax is " << tax;
		}
	}
	cout << endl;
	return 0;
}
