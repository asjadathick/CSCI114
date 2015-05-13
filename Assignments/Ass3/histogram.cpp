#include <iostream>
using namespace std;

int main()
{
	int input=0;
	int data[10];
	int max=0;
	int maxIndex=0;

	//initialize array
	for (int i=0; i<=9;i++)
	{
		data[i]=0;
	}
	cout<<"Enter numbers (-1 to stop)"<<endl;


	cin>>input;
	while (input!=-1)
	{
		data[input]++;
		//cout<<"for input: " <<input << "value is: " << data[input]<<endl;
		cin>>input;
	}

	//output histogram

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

		//cout<<"Max:"<<max<<endl;

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
	return 0;
}

//9 8 7 8 7 1 2 4 8 9 1 4 0 4 5 6 2 4 5 6 8 9 7 5 4 2 2 3 5 6 6 7 8 9 4 2 1 1 1 -1