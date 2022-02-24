//Project 1: Implementing File Input/Output with CStrings
//Author: Ethan Mahoney

#include <iostream>
#include <fstream>
#define MAX_NAMES 10
#define NAME_LENGTH 9

using namespace std;

//Function Prototypes
void readNames(char inputFile[], char Names[][NAME_LENGTH]);
void printNamesToTerminal(int size, char nameList[][NAME_LENGTH], int nameNumber[]);
void sortNamesAlphabetic(int size, char listNames[][NAME_LENGTH], int numList[]);
void sortNamesByLength(int nameCount, char nameArr[][NAME_LENGTH], int numbArr[]);
int myStringCompare(const char firstArray[], const char secondArray[]);
void myStringCopy(char destinationArray[], const char sourceArray[]);
int myStringLength(const char nameStr[]);
void printNamesToFile(char outputFile[], char names[][NAME_LENGTH], int numOrder[], int length);

int main()
{
    char inputName[100];
    char outputName[100];
    char namesArray[MAX_NAMES][NAME_LENGTH];
    int nameOrder[MAX_NAMES] = {0, 1, 2, 3, 4, 5, 6, 7, 8 , 9};

//Prompts user for the file names.

    cout << "Please enter the name of the input file: ";
    cin >> inputName;
    cout << "Please enter the name of the output file: ";
    cin >> outputName;

//Displays unsorted data from the input file and stores it into a file.

    cout << endl << "Unsorted Data (Original Input Order and Name)" << endl << "=====================" << endl;
    readNames(inputName, namesArray);
    printNamesToTerminal(MAX_NAMES, namesArray, nameOrder);

//Displays alphabetically sorted data.

    cout << endl << "Alphabetically Sorted Data (Original Input Order and Name)" << endl << "=====================" << endl;
    sortNamesAlphabetic(MAX_NAMES, namesArray, nameOrder);
    printNamesToTerminal(MAX_NAMES, namesArray, nameOrder);

//Displays length and alphabetically sorted data and stores it into a file.

    cout << endl << "Sorted-by-Length -and- Alphabetically Data (Original Input Order and Name)" << endl << "=====================" << endl;
    sortNamesByLength(MAX_NAMES, namesArray, nameOrder);
    printNamesToTerminal(MAX_NAMES, namesArray, nameOrder);
    cout << endl;
    printNamesToFile(outputName, namesArray, nameOrder, MAX_NAMES);

    return 0;
}

//Takes names from input file and stores them in appropriate array.

void readNames(char inputfile[], char Names[][NAME_LENGTH])
{
    ifstream infile;
    int index = 0;

    infile.open(inputfile);

    while(!infile.eof())
    {
        infile >> Names[index];
        index++;
    }

    infile.close();
}

//Prints the contents of the name and number array to the screen.

void printNamesToTerminal(int size, char nameList[][NAME_LENGTH], int nameNumber[])
{
    for(int index = 0; index < size; index++)
    {
        cout << nameNumber[index] << " " << nameList[index] << endl;
    }
}

//Sorts the array of names in alphabetical order.

void sortNamesAlphabetic(int size, char listNames[][NAME_LENGTH], int numList[])
{
    char temp[NAME_LENGTH];
    int tempNum;

    for(int index = 0; index < size; index++)
    {
        for(int index2 = index + 1; index2 < size; index2++)
        {
            if(myStringCompare(listNames[index], listNames[index2]) > 0)
            {
                myStringCopy(temp, listNames[index]);
                tempNum = numList[index];
                myStringCopy(listNames[index], listNames[index2]);
                numList[index] = numList[index2];
                myStringCopy(listNames[index2], temp);
                numList[index2] = tempNum;
            }

        }
    }
}

//Sorts the array of names by length and alphabetical order.

void sortNamesByLength(int nameCount, char nameArr[][NAME_LENGTH], int numbArr[])
{
    char tempName[NAME_LENGTH];
    int tempNums;

    for(int index = 0; index < nameCount - 1; index++)
    {
        for(int index2 = 0; index2 < nameCount - index - 1; index2++)
        {
            if(myStringLength(nameArr[index2]) > myStringLength(nameArr[index2+1]))
            {
                myStringCopy(tempName, nameArr[index2]);
                tempNums = numbArr[index2];
                myStringCopy(nameArr[index2], nameArr[index2+1]);
                numbArr[index2] = numbArr[index2+1];
                myStringCopy(nameArr[index2+1], tempName);
                numbArr[index2+1] = tempNums;
            }
            else if(myStringLength(nameArr[index2]) == myStringLength(nameArr[index2+1]))
            {
                if(myStringCompare(nameArr[index2], nameArr[index2+1]) == 0)
                {
                    myStringCopy(tempName, nameArr[index2]);
                    tempNums = numbArr[index2];
                    myStringCopy(nameArr[index2], nameArr[index2+1]);
                    numbArr[index2] = numbArr[index2+1];
                    myStringCopy(nameArr[index2+1], tempName);
                    numbArr[index2+1] = tempNums;
                }
            }
        }
    }
}

//Compares two strings from the name array.

int myStringCompare(const char firstArray[], const char secondArray[])
{
    int element = 0;
    while(firstArray[element] != '\0' && secondArray[element] != '\0')
    {
        if(firstArray[element] > secondArray[element])
        {
            return 1;
        }
        else if(firstArray[element] < secondArray[element])
        {
            return -1;
        }
        else
        {
            element++;
        }
    }

    return 0;
}

//Copies the contents of one array to another.

void myStringCopy(char destinationArray[], const char sourceArray[])
{
    int index;

    for(index = 0; sourceArray[index] != '\0'; index++)
    {
        destinationArray[index] = sourceArray[index];
    }
    destinationArray[index] = '\0';
}

//Counts the amount of letters in a string excluding the null character.

int myStringLength(const char nameStr[])
{
    int count = 0;

    while(nameStr[count] != '\0')
    {
        count++;
    }
    return count;
}

//Prints the array of names into the outputfile.

void printNamesToFile(char outf[], char names[][NAME_LENGTH], int numOrder[], int length)
{
    ofstream outfile;
    int index = 0;

    outfile.open(outf);
    
    outfile << "Sorted-by-Length -and- Alphabetically Data (Original Input Order and Name)" << endl << "=====================" << endl;

    while(index < length)
    {
        outfile << numOrder[index] << " " << names[index] << endl;
        index++;
    }
    outfile << endl;

    outfile.close();
}
