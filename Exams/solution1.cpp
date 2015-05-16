
#include <iostream>
using namespace std;

/*
	File: solution1.cpp
	CSCI114 Mid Session Exam
	Author: Asjad Athick 4970512

	Desc:

	Prompts user to input 5 integers and displays the largest int.
	Also, its input-safe yay.
	
*/

int main()
{
	int number1=0, number2=0, number3=0, number4=0, number5=0;
	int largest=0;

	cout << "Please enter 5 numbers: ";
	cin >> number1 >> number2 >> number3 >> number4 >> number5;

	largest = number1;

        if (largest < number2)
		largest = number2;
        if (largest < number3)
		largest = number3;
        if (largest < number4)
		largest = number4;
        if (largest < number5)
		largest = number5;
 	
	if (!cin.good())
		cout<<"Invalid input. Program accepts only integers"<<endl;
	else
		cout << "The largest number is: " << largest << endl;


	return 0;
}
