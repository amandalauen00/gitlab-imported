/*
    Mini-lab on C strings
    CSC 150 Fall 2019
    NAME: Amanda Lauen
*/

//Needed to use cstring functions
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    //TODO: Declare one cString to hold the final filename
    char Finalfilename[100];

    //TODO: Declare two cStrings to get user inputs
    char uInput1[41];
    char uInput2[41];

    //Ask for two user inputs
    cout << "Inputs should be < 40 characters." << endl;
    cout << "Enter first input string: ";
    //TODO: Get the first input into the first cString
    cin.getline(uInput1, 41);
    cout << "Enter second input string: ";
    //TODO: Get the second input into the second cString
    cin.getline(uInput2, 41);

    //TODO: Put them together (into the final cstring variable) in dictionary order.
    if (strcmp(uInput1, uInput2) < 0)
    {
        strcpy(Finalfilename, uInput1);
        strcat(Finalfilename, uInput2);
    }
    else
    {
        strcpy(Finalfilename, uInput2);
        strcat(Finalfilename, uInput1);
    }


    //Output the result
    cout << endl << "Put together: " << Finalfilename << endl;

    //TODO: Reverse the name
    for (size_t i = 0, j = strlen(Finalfilename) - 1; i < j; i++, j--)
    {
        char temp = Finalfilename[i];
        Finalfilename[i] = Finalfilename[j];
        Finalfilename[j] = temp;
    }

    //Output the result:
    cout << "Reversed: " << Finalfilename << endl;

    //TODO: Add on .txt to the result
    strcat(Finalfilename, ".txt");

    //Output the result:
    cout << "With file extension: " << Finalfilename << endl;

    //TODO: Change to all uppercase
    for (int i = 0; i < strlen(Finalfilename); i++)
        Finalfilename[i] = toupper(Finalfilename[i]);

    //Output the result
    cout << "All uppercase: " << Finalfilename << endl;

    return 0;
}