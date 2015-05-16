/*
Assignment 3
File: histogram.cpp
Author: Asjad Athick 4970512
Dependency files: None

Desc:

Accepts a sequence of integers from 0-9, counts frequency of numbers
and prints a histogram. Input safe.
*/

#include <iostream>
using namespace std;

int main()
{
	int input=0;
	int data[10];
	int max=0;
	int maxIndex=0;
	bool invalidInput=false;

	//initialize array
	for (int i=0; i<=9;i++)
	{
		data[i]=0;
	}
	cout<<"Enter numbers (-1 to stop)"<<endl;


	cin>>input;
	while (input!=-1 && invalidInput==false)
	{
		if (input>=0 && input<=9)
		{
			//record occurences
			data[input]++;
			cin>>input;
		}
		else
		{
			invalidInput=true;
		}
	}

	//output histogram if input was valid

	if (invalidInput==false)
	{
		do
		{
			max=-1;
			for (int i=0;i<=9;i++)
			{
				if (data[i]>max)
				{
					max=data[i];
				}
			}


			if (max!=0){
				for (int i=0; i<=9;i++)
				{
					if (data[i]==max)
					{
						cout<<"* ";
						data[i]--;
					}
					else
					{
						cout<<"  ";
					}
				}
				cout<<endl;
			}
		}while(!(max==0));


		cout << "-------------------"<<endl;
		cout << "0 1 2 3 4 5 6 7 8 9"<<endl;
	}
	else
	{
		cout<<"Invalid input, only enter integers from 0 to 9." <<endl;
	}
	return 0;
}
