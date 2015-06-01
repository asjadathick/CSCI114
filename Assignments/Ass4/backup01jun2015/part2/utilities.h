#include <iostream>
#include <cstring>
#include <fstream>
#include "vignere.h"

using namespace std;

void inputString(char str[]);
void encrypt(ifstream &input, ofstream &output, char key[]);
void decrypt(ifstream &input, ofstream &output, char key[]);