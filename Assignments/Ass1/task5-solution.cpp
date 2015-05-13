/*************************************************************************************
 * Filename:		task5-solution.cpp					     *
 * Assignment:		1							     *
 * File Desc:		Takes 10 integers as input and outputs the average.	     *
 * Date Last Modified:	26 March 2015						     *
 * Author:		Asjad Athick (4970512)					     *
 ************************************************************************************/

/*
Sample data: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10. 
Hand Calculated average: 5.5
Computed Average: 5.5
*/
#include <iostream>
using namespace std;

int main()
{
    
	int num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0,num10=0;
	int total=0;
	double average=0;
    
	cout<<"Input 10 numbers, seperated by new lines" <<endl;
	cin>>num1>>num2>>num3>>num4>>num5>>num6>>num7>>num8>>num9>>num10;

	//calculate total
	total=num1+num2+num3+num4+num5+num6+num7+num8+num9+num10;

	//calculate average
	average=total/10.0;
    
	//output numbers
	cout<<num1<<" "<<num2<<" "<<num3<<" "<<num4<<" "<<num5<<" "<<num6<<" "<<num7<<" "<<num8<<" "<<num9<<" "<<num10<<endl;
    
	//output average
	cout<<"Average: " << average << endl;
    
	return 0;
    
}
