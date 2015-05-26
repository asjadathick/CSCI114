#include "CDWeb.h"
#include "CDWebUtilities.h"

cdFile data[200];
bool databaseChanged=false;

void PrintMenu()
{
    cout << "CDWeb Inventory\nCommands Available:\n";
    cout << "  A - add new CD record\n";
    cout << "  C - change the stock level\n";
    cout << "  D - display a selected title\n";
    cout << "  L - list by genre or artist\n";
    cout << "  M - print this menu\n";
    cout << "  S - store the in-memory DB onto file\n";
    cout << "  V - summarise the value of the current inventory\n";
    cout << "  R - Remove a CD record\n";
    cout << "  Q - terminate the program" << endl;
}

void LoadDB()
{
    ifstream CDWebFile;
    CDWebFile.open(fileName);
    
    string inputBuffer;
    int lineCount=0, recordCount=0;
    
    getline(CDWebFile, inputBuffer, '\n');
    while (!CDWebFile.eof() && recordCount<=200)
    {
        //id
        data[recordCount].id=stof(inputBuffer);
        lineCount++;
        
        //title
        getline(CDWebFile, inputBuffer, '\n');
        data[recordCount].title=inputBuffer;
        lineCount++;
        
        //recording artist
        getline(CDWebFile, inputBuffer, '\n');
        data[recordCount].recordingArtist=inputBuffer;
        lineCount++;
        
        //durationmin
        getline(CDWebFile, inputBuffer, ' ');
        data[recordCount].durationMin=stof(inputBuffer);
        lineCount++;
        
        //durationsec
        getline(CDWebFile, inputBuffer, '\n');
        data[recordCount].durationSec=stof(inputBuffer);
        lineCount++;
        
        //listprice
        getline(CDWebFile, inputBuffer, '\n');
        data[recordCount].listPrice=stof(inputBuffer);
        lineCount++;
        
        //stock
        getline(CDWebFile, inputBuffer, '\n');
        data[recordCount].stock=stof(inputBuffer);
        lineCount++;
        
        //genre
        getline(CDWebFile, inputBuffer, '\n');
        data[recordCount].genre=inputBuffer;
        lineCount++;
        
        //change inuse flag
        data[recordCount].inUse=true;
        
        recordCount++;
        
        getline(CDWebFile, inputBuffer, '\n');
    }
    
    cout<<recordCount<< " records loaded." <<endl;
    
}
void YourAddCD()
{
    int recordID=0;
    bool foundFlag=false;
    //find empty record
    for (int i=0; i<200 && foundFlag==false; i++)
    {
        if (data[i].inUse==false)
        {
            recordID=i;
            foundFlag=true;
        }
        
    }
    
    if (foundFlag==false)
    {
        cout<<"Memory is full. "<<endl;
    }
    else
    {
        data[recordID].inUse=true;
        cout<<"Identification Number: ";
        data[recordID].id=inputInt();
        cout<<"Title: ";
        data[recordID].title=inputString();
        cout<<"Recorded: "<<data[recordID].title<<endl;
        cout<<"Recording Artist: ";
        data[recordID].recordingArtist=inputString();
        cout<<"Recorded: "<<data[recordID].recordingArtist<<endl;
        cout<<"Duration Min: ";
        data[recordID].durationMin=inputUnsignedInt();
        cout<<"Duration Sec: ";
        data[recordID].durationSec=inputUnsignedInt();
        cout<<"List price: ";
        data[recordID].listPrice=inputFloat();
        cout<<"Stock: ";
        data[recordID].stock=inputUnsignedInt();
        cout<<"Genre: ";
        data[recordID].genre=inputString();
        cout<<"Record Added"<<endl;
        databaseChanged=true;
    }
    
}
void YourModifyStockLevel()
{
    //accepts ID number int and change int, and changes the stock level by the change
    //If change makes stock negative, makes it 0.
    int ID;
    int change;
    int stock; //intermediary variable
    
    cout<<"Identification Number? : ";
    ID=inputInt();
    cout<<"Change by? : ";
    change=inputInt();
    
    //find record at id
    bool foundFlag=false;
    int foundIndex=0;
    
    for (int i=0; i<200 && foundFlag==false; i++)
    {
        if (data[i].id==ID && data[i].inUse==true)
        {
            foundFlag=true;
            foundIndex=i;
        }
    }
    
    if (foundFlag==false)
    {
        cout<<"Record not found. Stock level not updated."<<endl;
    }
    else
    {
        stock=data[foundIndex].stock;
        if ((stock+change)<0)
        {
            cout<<"This change results in negative stock. Stock set to 0"<<endl;
            data[foundIndex].stock=0;
        }
        else
        {
            data[foundIndex].stock+=change;
            cout<<"Stock changed by " << change << " to: " << data[foundIndex].stock<<endl;
        }
        databaseChanged=true;
    }

    
}
void YourDisplayCD()
{
    int searchKey=0;
    
    cout<<"Enter Identification Number: "<<endl;
    searchKey=inputInt();
    
    bool foundFlag=false;
    int foundIndex=0;
    
    for (int i=0; i<200 && foundFlag==false; i++)
    {
        if (data[i].id==searchKey && data[i].inUse==true)
        {
            foundFlag=true;
            foundIndex=i;
        }
    }
    
    if (foundFlag==false)
    {
        cout<<"CD Details not found on file."<<endl;
    }
    else
    {
        cout<<"CD Data: "<<endl;
        cout<< "ID: " << data[foundIndex].id<<endl;
        cout<<"Title: " << data[foundIndex].title<<endl;
        cout<<"Stock: " << data[foundIndex].stock<<endl;
        //do the rest later
    }
    
    
}
void YourList()
{
    
}
void YourStoreDB()
{
    if (databaseChanged==true)
    {
        //save to file
        ofstream CDWebFile;
        CDWebFile.open(fileName);
        
        for (int i=0; i<200; i++)
        {
            if (data[i].inUse==true)
            {
                CDWebFile<<data[i].id<<"\n"<<data[i].title<<"\n"<<data[i].recordingArtist<<"\n"<<data[i].durationMin<<" "<<data[i].durationSec<<"\n"<<data[i].listPrice<<"\n"<<data[i].stock<<"\n"<<data[i].genre<<"\n";
            }
        }
        
        CDWebFile.close();
        
        databaseChanged=false;
    }
    cout<<"Changes saved to file."<<endl;
}
void YourSummary()
{
    
}
void YourRemove()
{
    int removeID;
    cout<<"Enter Identification Number: ";
    removeID=inputInt();
    
    bool foundFlag=false;
    int foundIndex=0;
    
    for (int i=0; i<200 && foundFlag==false; i++)
    {
        if (data[i].id==removeID && data[i].inUse==true)
        {
            foundFlag=true;
            foundIndex=i;
        }
    }
    
    if (foundFlag==false)
    {
        cout<<"CD Details not found on file."<<endl;
    }
    else
    {
        data[foundIndex].inUse=false;
        cout<<"Record removed."<<endl;
        databaseChanged=true;
    }

}
