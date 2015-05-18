#include <iostream>
#include <iomanip>

using namespace std;

const int NUMBER_OF_DICE = 5;
const char SCORE_CATEGORIES[13][30]=
{
    {"Aces"},
    {"Twos"},
    {"Threes"},
    {"Fours"},
    {"Fives"},
    {"Sixes"},
    {"3 of a kind"},
    {"4 of a kind"},
    {"Full House"},
    {"Small Straight"},
    {"Large Straight"},
    {"Yahtzee"},
    {"Chance"}
};

//program method prototypes
void setSeed();
void rollDice(int diceValues[]);
void reRollDice(int diceValues[]);
void calculateScores(int input[], int scores[]);
void printProjectedScores(int scores[]);
int chooseCategory(bool categories[]);
void recordAndPrintScore(int chosenCategory, int scores[], int& totalScore, int& bonusCatScore);

//score calculating method prototypes
void firstSix(int input[], int scores[]);
int ofaKind(int input[], int kind);
int fullHouse(int input[]);
int smallStraight(int input[]);
int largeStraight(int input[]);
int yahtzee(int input[]);
int chance(int input[]);

//utility method prototypes
void initializeIntArray(int array[],int upperBound);
int sumOfArray(int array[], int upperBound);
void copyArray(int toArray[], int fromArray[], int upperBound);
void sortArray(int array[], int ARRAY_SIZE);
void outputArray(int array[], int upperBound);
void emptyStream();


 int main()
 {
    //doesnt require re initialization
    int totalScore=0;
    int bonusCatScore=0;
    bool categories[13];
    bool successfulInput=true;
    
    for (int i=0; i<=13; i++)
    {
        categories[i]=false;
    }
    
    setSeed();
    
    //game loop
    for (int i=1; i<=13 && successfulInput==true; i++)
    {
        //initialization/declarations
        int diceValues[NUMBER_OF_DICE];
        int chosenCategory=0;
        initializeIntArray(diceValues,NUMBER_OF_DICE);
        
        int scores[13];
        initializeIntArray(scores,13);
        
        cout<<"Round " <<i<<endl;
        
        rollDice(diceValues);
        reRollDice(diceValues);

        calculateScores(diceValues,scores);
        printProjectedScores(scores);
        chosenCategory=chooseCategory(categories);
        
            //update score according to chosen category
        recordAndPrintScore(chosenCategory,scores,totalScore,bonusCatScore);
        
    }
    
    
    
    if (bonusCatScore>62)
        totalScore+=bonusCatScore;
    
    cout<<"Your total score: " <<totalScore<<endl;
    
    
    return 0;
 }

void setSeed()
{
    long seed=0;
    
    cout<<"Enter Seed: " << endl;
    cin>>seed;
    
    while (!cin.good())
    {
        if (!cin.good())
        {
            cout<<"Invalid input: Please enter a long integer."<<endl;
            emptyStream();
            cout<<"Enter Seed: " << endl;
            cin>>seed;
        }
        
    }
    
    srand(seed);
    
}
void rollDice(int diceValues[]) //functional
{
    //assign random nums to dice values
    
    for (int i=0; i<NUMBER_OF_DICE; i++)
    {
        diceValues[i]=(rand()%6)+1;
    }
    
}

void reRollDice(int diceValues[])
{
    char charBuffer;
    bool successful=false;
    char rerollInstructions[NUMBER_OF_DICE];
    
    while (successful==false)
    {
        successful=true;
        cout << "The dice were \t";
        for (int i=0; i<NUMBER_OF_DICE; i++)
        {
            cout<<diceValues[i];
        }
        cout << endl;
        cout << "What re-rolls? \t";
        for (int i=0; i<NUMBER_OF_DICE; i++)
        {
            cin>>rerollInstructions[i];
        }
        
        //perform validation
        for (int i=0;i<NUMBER_OF_DICE;i++)
        {
            if (!(rerollInstructions[i]=='r' || rerollInstructions[i]=='h' || rerollInstructions[i]=='R' || rerollInstructions[i]=='H'))
            {
                successful=false;
            }
        }
        
        
        if (!successful)
            cout<<"Invalid input: Only enter h to hold, or r to re-roll"<<endl;
        emptyStream();
    }
    
    if (successful)
    {
        //do re-rolls
        for (int count=0; count<NUMBER_OF_DICE; count++)
        {
            
            if (rerollInstructions[count]=='r'||rerollInstructions[count]=='R')
                diceValues[count]=(rand()%6)+1;
            
        }
        
        cout<<"The dice were \t";
        for (int i=0; i<NUMBER_OF_DICE;i++)
        {
            cout<<diceValues[i];
        }
        cout<<endl;
    }
    
}

//methods for score calculation
void calculateScores(int input[], int scores[])
{
    //calls all score calculating methods
    firstSix(input,scores);
    //3 of a kind
    scores[6]=ofaKind(input,3);
    //4 of a kind
    scores[7]=ofaKind(input,4);
    
    //full house
    scores[8]=fullHouse(input);
    //small straight
    scores[9]=smallStraight(input);
    //large straight
    scores[10]=largeStraight(input);
    //yahtzee
    scores[11]=yahtzee(input);
    //chance
    scores[12]=chance(input);
    
}

void printProjectedScores(int scores[])
{
    for (int i=0; i<13; i++)
    {
        cout<<i+1<<"."<<"\t";
        cout<<setw(20)<<left<<SCORE_CATEGORIES[i];
        cout<<": " << scores[i]<<endl;
    }
}

int chooseCategory(bool categories[])
{
    int inputCategory=0;
    bool categoryValid=false;
    int result=0;
    
    while (categoryValid==false)
    {
        
        cout<<"Which category? ";
        cin>>inputCategory;
        while (!cin.good())
        {
            if (!cin.good())
            {
                cout<<"Invalid input: Please enter a long integer."<<endl;
                emptyStream();
                cout<<"Which category? ";
                cin>>inputCategory;
            }
            
        }
        
        
        
        
        if (inputCategory>0 && inputCategory<14)
        {
            //valid
            if (categories[inputCategory-1]==false)
            {
                categories[inputCategory-1]=true;
                categoryValid=true;
            }
        }
        
        if (categoryValid==false)
        {
            cout<<"Bad category Please retry? " <<endl;
        }
        else
        {
            result=inputCategory-1;
        }
    }
    return result;
}

void recordAndPrintScore(int chosenCategory, int scores[], int& totalScore, int& bonusCatScore)
{
    //bonus calc
    if (chosenCategory>=0 && chosenCategory<6)
        bonusCatScore+=scores[chosenCategory];
    
    //normal total
    totalScore+=scores[chosenCategory];
    cout<<"Score recorded for round: " << scores[chosenCategory]<<endl;
    cout<<"Score for first six Categories: " <<bonusCatScore<<endl;
}

void firstSix(int input[], int scores[])
{
    for (int i=0; i<=NUMBER_OF_DICE; i++)
    {
        for (int j=0; j<=NUMBER_OF_DICE;j++)
        {
            if (input[i]==(j+1))
                scores[input[i]-1]+=(j+1);
        }
    }
}

int ofaKind(int input[], int kind)
{
    int returnVal=0;
    int occurences[6];
    
    initializeIntArray(occurences,6);
    
    for (int i=0;i<NUMBER_OF_DICE;i++)
    {
        occurences[input[i]-1]++;
    }
    
    
    for (int i=0;i<NUMBER_OF_DICE;i++)
    {
        
        if (occurences[i]>=kind)
        {
            returnVal= sumOfArray(input,NUMBER_OF_DICE);
        }
    }
    return returnVal;
}

int fullHouse(int input[])
{
    bool twoFound=false;
    bool threeFound=false;
    int occurences[6];
    
    int result=0;
    
    initializeIntArray(occurences,6);
    
    for (int i=0; i<NUMBER_OF_DICE; i++)
    {
        occurences[input[i]-1]++;
    }
    
    
    for (int i=0; i<6;i++)
    {
        if (occurences[i]==2)
            twoFound=true;
        if (occurences[i]==3)
            threeFound=true;
    }
    
    if (twoFound&&threeFound)
        result= 25;
    
    return result;
}

int smallStraight(int input[])
{
    int result=0;
    int inputCopy[NUMBER_OF_DICE];
    initializeIntArray(inputCopy,NUMBER_OF_DICE);
    copyArray(inputCopy,input,NUMBER_OF_DICE);
    sortArray(inputCopy,NUMBER_OF_DICE);
    int compValue=inputCopy[0];
    int compCount=0;
    
    //compare with flag
    
    
    for (int i=0; i<NUMBER_OF_DICE;i++)
    {
        if (inputCopy[i]==compValue+1)
        {
            compCount++;
        }
        else
        {
            compCount=0;
        }
        
        if (compCount==3)
        {
            //small straight
            result=30;
        }
        compValue=inputCopy[i];
    }
    return result;
}

int largeStraight(int input[])
{
    int result=0;
    int inputCopy[NUMBER_OF_DICE];
    initializeIntArray(inputCopy,NUMBER_OF_DICE);
    copyArray(inputCopy,input,NUMBER_OF_DICE);
    sortArray(inputCopy,NUMBER_OF_DICE);
    int compValue=inputCopy[0];
    int compCount=0;
    
    //compare with flag
    
    for (int i=0; i<NUMBER_OF_DICE;i++)
    {
        if (inputCopy[i]==compValue+1)
        {
            compCount++;
        }
        else
        {
            compCount=0;
        }
        
        if (compCount==4)
        {
            //large straight
            result=40;
        }
        compValue=inputCopy[i];
    }
    return result;
}

int yahtzee(int input[])
{
    int result=0;
    int checkValue=input[0];
    bool falseFlag=false;
    
    for (int i=0; i<NUMBER_OF_DICE;i++)
    {
        if (!(input[i]==checkValue))
            falseFlag=true;
    }
    
    if (!falseFlag)
        result=50;
    
    return result;
}

int chance(int input[])
{
    return sumOfArray(input,NUMBER_OF_DICE);
}

void initializeIntArray(int array[],int upperBound)
{
    for (int i=0; i<upperBound;i++)
    {
        array[i]=0;
    }
}

int sumOfArray(int array[], int upperBound)
{
    int returnVal=0;
    for (int i=0; i<upperBound;i++)
    {
        returnVal+=array[i];
    }
    return returnVal;
}

void copyArray(int toArray[], int fromArray[], int upperBound)
{
    for (int i=0; i<upperBound; i++)
    {
        toArray[i]=fromArray[i];
    }
}

void sortArray(int array[], int ARRAY_SIZE)
{
    int numSorted=0;
    int minIndex=0;
    int temp=0;
    
    while (numSorted<ARRAY_SIZE)
    {
        //find smallest element in unsorted
        minIndex=numSorted;
        for (int i=numSorted+1; i<ARRAY_SIZE; i++)
        {
            if (array[i]<array[minIndex])
            {
                minIndex=i;
            }
        }
        //swap
        if (minIndex!=0)
        {
            temp=array[numSorted];
            array[numSorted]=array[minIndex];
            array[minIndex]=temp;
        }
        numSorted++;
    }
    
}


void outputArray(int array[], int upperBound) //functional
{
    for (int i=0; i<upperBound;i++)
    {
        cout<< i<< " :" << array[i]<<endl;
    }
}

void emptyStream()
{
    cin.clear();
    cin.ignore(1000, '\n');
}