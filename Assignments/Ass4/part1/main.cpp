
#include "CDWeb.h"


int main()
{
    char command;
    
    LoadDB();		// should report the number of records loaded
    PrintMenu();
    
    do
    {
        cout << "\nCDWeb Command:" << endl;
        cin >> command;
        switch (command)
        {
            case 'A':
                YourAddCD();
                break;
            case 'C':
                YourModifyStockLevel();
                break;
            case 'D':
                YourDisplayCD();
                break;
            case 'L':
                YourList();
                break;
            case 'M':
                PrintMenu();
                break;
            case 'S':
                YourStoreDB();
                break;
            case 'V':
                YourSummary();
                break;
            case 'R':
                YourRemove();
                break;
            case 'Q':
                break;
            default:
                cerr << "Illegal CDWeb Command\n";
                PrintMenu();
        }
    } while (command != 'Q');
    YourStoreDB();
    return 0;
}

