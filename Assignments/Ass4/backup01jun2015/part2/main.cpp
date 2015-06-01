
#include "utilities.h"

int main()
{
    char sourceFile[256];
    char outputFile[256];
    char key[9];
    char action;
    bool validInput=true;
    
    cout<<"Enter source file: ";
    inputString(sourceFile);
    
    cout<<"Enter output file: ";
    inputString(outputFile);
    
    cout<<"Enter key (8 chars max): ";
    inputString(key);
    //do some checking maybes?
    
    cout<<"Encrypt or Decrypt? (e/d)? ";
    cin>>action;
    
    //check if valid
    if (action=='e' || action=='E' || action=='d' || action=='D')
    {
        if (action=='e' || action=='d' )
        {
            action-=32;
        }
    }
    else
    {
        cout<<"Invalid action. Program will terminate."<<endl;
        validInput=false;
    }
    
    if (validInput)
    {
        ifstream Input;
        Input.open(sourceFile);
        
        if (!Input)
        {
            cout<<"Could not open source file"<<endl;
        }
        else
        {
            ofstream Output;
            Output.open(outputFile);
            if (!Output)
            {
                cout<<"Could not open output file"<<endl;
            }
            else
            {
                if (action=='E')
                    encrypt(Input, Output, key);
                if (action=='D')
                    decrypt(Input, Output, key);
            }
        }
    }
    
    return 0;
}