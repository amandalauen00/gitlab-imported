/*
    CSC 150 Fall 2019
    Lab 12: Cstrings
    NAME: Amanda Lauen
*/

//This define is needed to avoid Visual Studio cstring function warnings
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

void printCounts(int letterCounts[]);
//TODO: Add more prototypes here
bool isPalindrome(char user_input[]);
void countLetters(char user_input[], int letterCounts[]);


int main()
{
    //TODO: Declare a C string to hold the user's input message.
    char user_input[81];

    //TODO: Declare an array to hold counts of each letter in the alphabet.
    int letterCounts[26];

    //TODO: Since we are going to sum the letter counts,
    // we must initialize all elements of the counts
    // array to zero.

    for (int i = 0; i < 26; i++)
    {
        letterCounts[i] = 0;
    }

    //Ask for user input string
    cout << "Enter your message, up to 80 characters: " << endl;

    //TODO: Read in the user's input string
    cin.getline(user_input, 81);

    //This endl is in the starter file for formatting purposes
    cout << endl;

    //TODO: Find and output whether it is a palindrome or not,
    //  using the isPalindrome function.
    bool palindrome = isPalindrome(user_input);
    if (palindrome == true)
    {
        cout << "Your message is a palindrome." << endl;
    }
    else
    {
        cout << "Not a palindrome." << endl;
    }

    //TODO: Call the function to count the letters
    countLetters(user_input, letterCounts);
        
    //TODO: Finish this function call to output the counts
    printCounts(letterCounts);

    return 0;
}

/** ***************************************************************************
* @author K Corwin
*
* @par Description:
* This function takes in an array of counts of letters.  The function
    prints out the contents of each array element, labeled with the
    appropriate letter of the alphabet (i.e. the value in the first
    element is labeled A: , the second element is labeled B: , etc.).
*
* @param[in] letterCounts - the array of letter counts
*
* @returns none
*****************************************************************************/
void printCounts(int letterCounts[])
{
    char letter = 'A';
    for (int index = 0; index < 26; index++)
    {
        cout << letter << ": " << letterCounts[index] << endl;
        letter++;
    }
}

/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This fucntion takes in the user input and creates a copy of that input
*      with an index of 81.  The function then copy's the input into a defined
*      uI_copy  variable and compared it to see it it equals zero.  If it does,
*      then the function retruns true.  If it doesn't equal zero, then the
*      function returns false.
*
* @param[in] user_input - the array of the user input
*
* @returns true if uIcopy = user_input, false otherwise
*****************************************************************************/
bool isPalindrome(char user_input[])
{
    char uI_copy[81];
    strcpy(uI_copy, user_input);
    _strrev(uI_copy);
    if (strcmp(uI_copy,user_input)== 0)
    {
        return true;
    }
    return false;
}

/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This function takes in the user input and the letter counts arrays and
*      gets the length of the user input by using strlen.  Then the function 
*      makes the message all uppercase.  The function then goes inot a loop and
*      inside the loop the variable index is the user input minus the first 
*      character 'A' to find the current index.  Then it compares if the index
*      is less than or equal to 25 in order to increment the letterCounts array.
*      This function does not return anything.
*
* @param[in] user_input - the array of the user input
* @param[in] letterCounts - the array of the current letter counts
*
* @returns none
*****************************************************************************/
void countLetters(char user_input[], int letterCounts[])
{
    int index = 0;
    int length = (int)strlen(user_input);
    _strupr(user_input);
    for (int i = 0; i < length; i++)
    {
        index = (int)(user_input[i] - 'A');
        if ((index > -1) && (index <= 25))
        {
            letterCounts[index]++;
        }
        
    }
}