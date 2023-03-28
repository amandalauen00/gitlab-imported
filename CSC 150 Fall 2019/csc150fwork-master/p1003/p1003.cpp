/*
CSC 150 Fall 2019
Lab 6 p1003
Amanda Lauen
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>

using namespace std;


int main()
{
    //Intitalize characters
    char user_password_value_1;
    char user_password_value_2;
    char user_password_value_3;

    //Ask user for a 3 character password
    cout << "Enter your 3-character password: ";
    cin >> user_password_value_1 >> user_password_value_2 >> user_password_value_3;

    //Check to see if all the values are the same
    if ((isalpha(user_password_value_1) && isalpha(user_password_value_2) 
        && isalpha(user_password_value_3)) || (isdigit(user_password_value_1) 
        && isdigit(user_password_value_2) && isdigit(user_password_value_3))
        || (ispunct(user_password_value_1) && ispunct(user_password_value_2) 
        && ispunct(user_password_value_3)))
    {
        cout << "All characters in password are of the same type." << endl;
    }

    //Check to see if there is a digit in the password
    if (isdigit(user_password_value_1) || isdigit(user_password_value_2) || isdigit(user_password_value_3))
    {   
        cout << "Password contains a number." << endl;
    }

    //Check to see if there is punctuation in the password
    if (ispunct(user_password_value_1) || ispunct(user_password_value_2) || ispunct(user_password_value_3))
    {
        cout << "Password contains a punctuation mark." << endl;
    }

    //Check to see if there is letters in the password
    if (isalpha(user_password_value_1) || isalpha(user_password_value_2) || isalpha(user_password_value_3))
    {
        cout << "Password contains a letter." << endl;
        cout << "The password all uppercase is: " << (char)toupper(user_password_value_1)
             << (char)toupper(user_password_value_2) 
             << (char)toupper(user_password_value_3) << endl;
        cout << "The password all lowercase is: " << (char)tolower(user_password_value_1)
             << (char)tolower(user_password_value_2) 
             << (char)tolower(user_password_value_3) << endl;
    }
     
    //End program
    return 0;
}