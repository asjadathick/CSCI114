#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//method prototypes
void PrintMenu();
void LoadDB();
void YourAddCD();
void YourModifyStockLevel();
void YourDisplayCD();
void YourList();
void YourStoreDB();
void YourSummary();
void YourRemove();


//struct declaration
struct cdFile
{
    int id;
    string title;
    string recordingArtist;
    unsigned int durationMin, durationSec;
    float listPrice;
    unsigned int stock;
    string genre;
    bool inUse=false;
};

//global consts
//update this later
const char fileName[200] = {"../../../../../../../../Documents/ass4final/ass4final/CDdata.txt"};