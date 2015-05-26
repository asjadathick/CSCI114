

#include "CDWebUtilities.h"
#include "CDWeb.h"

void clearStream()
{
    cin.clear();
    cin.ignore(1000,'\n');
}

int inputInt()
{
    clearStream();
    int input;
    cin>>input;
    while (!cin.good())
    {
        clearStream();
        cout<<"Invalid Input, please enter an integer: "<<endl;
        cin>>input;
        
    }
    return input;
}

unsigned int inputUnsignedInt()
{
    clearStream();
    unsigned int input;
    cin>>input;
    while (!cin.good())
    {
        clearStream();
        cout<<"Invalid Input, please enter an unsigned integer: "<<endl;
        cin>>input;
        
    }
    return input;
}

float inputFloat()
{
    clearStream();
    float input;
    cin>>input;
    while (!cin.good())
    {
        clearStream();
        cout<<"Invalid Input, please enter a real number: "<<endl;
        cin>>input;
        
    }
    return input;

}

string inputString()
{
    clearStream();
    
    char input[256];
    string result;
    cin.getline(input, 256, '\n');
    result=input;
    
    
    return result;

}