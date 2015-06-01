

#include "utilities.h"

void inputString(char str[])
{
    cin.getline(str, 256);
}

void encrypt(ifstream &input, ofstream &output, char key[])
{
    char inputBuffer[1000]; //assumed each line < 999 chars.
    while (!input.eof())
    {
        input.getline(inputBuffer, 999);
        vignere_encrypt(inputBuffer, key);
        output<<inputBuffer<<endl;
    }
    cout<<"Encrypted source file to output file"<<endl;
}

void decrypt(ifstream &input, ofstream &output, char key[])
{
    char inputBuffer[1000]; //assumed each line < 999 chars.
    while (!input.eof())
    {
        input.getline(inputBuffer, 999);
        vignere_decrypt(inputBuffer, key);
        output<<inputBuffer<<endl;
        
    }
    cout<<"Decrypted source file to output file"<<endl;
}