/*
CSC 150 Fall 2019
Lab 5 p1004
Amanda Lauen
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //Declare variables
    int user_input1;
    int user_input2;
    int user_terms;
    int i;
    int result;

    //Ask user for first term in sequence
    cout << "Enter first term: ";
    cin >> user_input1;

    //Ask user for second term in sequence
    cout << "Enter second term: ";
    cin >> user_input2;

    //Ask user for the number of terms they want in sequence
    cout << "Enter number of terms to follow: ";
    cin >> user_terms;

    //Print out sequence numbers
    cout << "Sequence:";
    cout << endl;
    cout << user_input1 << endl << user_input2 << endl;

    for (i = 0; i < user_terms; i++)
    {
         //Calculate result of both inputs
         result = user_input1 + user_input2; 
         //Print result
         cout << result << endl;
         //Show that the new input becomes the old input
         user_input1 = user_input2;
         user_input2 = result;
    }
    
    //Ends program
    return 0;
}





