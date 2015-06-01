

#include "CDWebUtilities.h"
#include "CDWeb.h"

bool stringStreamCleared=false;

void clearStream()
{
    cin.clear();
    cin.putback('\n');
    cin.ignore(1000,'\n');

}

void clearStreamForStrings()
{
    if (cin.peek()=='\n')
    {
        cin.ignore();
    }
    
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
    clearStreamForStrings();
    
    char str[256];
    string result;
    cin.getline(str, 256);
    return str;
    
    /*
    char input[256];
    char inputBuffer;
    int count=0;
    inputBuffer=cin.get();
    while (inputBuffer!='\n' && count<254)
    {
        input[count]=inputBuffer;
        count++;
        inputBuffer=cin.get();
    }
    input[count]='\0';
    return input;
*/
    
     
}