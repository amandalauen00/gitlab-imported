//CSC 150 Lab 14
//Fall 2019
//Song Rankings Revisited 
//Sorting (with files and command line)
//NAME: Amanda Lauen

//This define is needed to avoid Visual Studio cstring function warnings
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

using namespace std;

void swapIntegers(int& n1, int& n2);
void swapCStrings(char s1[], char s2[]);
//TODO: add more prototypes here
int readSongsRanks(ifstream &inSongs, ifstream &inRanks, int ranks[], char songs[][81], int max_elements);
void sortSongsByRank(int ranks[], char songs[][81], int numSongs);
void writeList(ofstream &out, int ranks[], char songs[][81], int numSongs);

/** ***************************************************************************
* @author K. Corwin
*
* @par Description:
*   Declares arrays
    Checks value of argc; if incorrect, terminates program
    Opens two input files and one output file
    Checks file success;  if incorrect, terminates program
    Reads from input files, obtaining number of data items read
    Sorts the song titles and ranking data based on rankings,
        in ascending order
    Writes the rankings and song titles, in ascending order,
        to the output file
    Closes all files
*
* @param[in] argc - the number of arguments from the command line.
* @param[in] argv - a 2d array of char containing the command line arguments.
*
* @returns 0 in all cases - a message to stdout describes any error states.
*
*****************************************************************************/
int main(int argc, char* argv[])
{
    //Declare two input file objects
    ifstream inSongs;
    ifstream inRanks;

    //Declare one output file object
    ofstream out;

    //Holds the song titles
    char songs[100][81];

    //Holds the song rankings
    int ranks[100];

    //The actual number of songs read from the files.
    int numSongs;

    //Always error check argc before doing anything else!!
    if (argc != 4)
    {
        cout << "Usage: p1014.exe <song filename> "
            << "<rank filename> <final list filename>" << endl;
        return 0;
    }

    //now try to open all 3 files
    inSongs.open(argv[1]);
    inRanks.open(argv[2]);
    out.open(argv[3]);

    //if any file fails to open, stop the program
    if (!inSongs || !inRanks || !out)
    {
        cout << "File error; program exiting." << endl;
        return 0;
    }

    //Read from both files, storing to arrays
    // and getting the actual value of numSongs
    numSongs = readSongsRanks(inSongs, inRanks, ranks, songs, 100);

    //Sort song and ranking data by rank
    sortSongsByRank(ranks, songs, numSongs);

    //Write the output to a new file
    writeList(out, ranks, songs, numSongs);

    //close all files
    inSongs.close();
    inRanks.close();
    out.close();

    return 0;
}

//TODO: add your function definitions

/** ***************************************************************************
* @author K. Corwin
*
* @par Description:
* This function takes in two integers by reference
    and swaps them.  When the function is done,
    n1 contains the original value of n2, and
    n2 contains the original value of n1.

    Note: this is a great example of [in,out] params!
*
* @param[in,out] n1 - at the call, this contains the first integer value;
                      at return, this contains the second integer value.
* @param[in,out] n2 - at the call, this contains the second integer value;
                      at return, this contains the first integer value.
*
* @returns none
*****************************************************************************/
void swapIntegers(int& n1, int& n2)
{
    //need a temporary integer for swapping,
    // then perform the 3 swap actions
    int swap = n2;
    n2 = n1;
    n1 = swap;

    return;
}

/** ***************************************************************************
* @author K. Corwin
*
* @par Description:
* This function takes in two C strings
    and swaps them.  When the function is done,
    s1 contains the original value of s2, and
    s2 contains the original value of s1.

    Note: this is a great example of [in,out] params!
*
* @param[in,out] s1 - at the call, this contains the first C string value;
                        at return, this contains the second C string value.
* @param[in,out] s2 - at the call, this contains the second C string value;
                        at return, this contains the first C string value.
*
* @returns none
*****************************************************************************/
void swapCStrings(char s1[], char s2[])
{
    //need a temporary C string for swapping
    char temp[81] = "";

    //perform the 3 actions to swap 2 values
    strcpy(temp, s2);
    strcpy(s2, s1);
    strcpy(s1, temp);

    return;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This function reads the rankings and song titles until the arrays are full
*      or until the end of a file is reached. The function returns the number of 
*      array elements/rows that were actually filled. 
*
* @param[in,out] inSongs - This is the variable has has the input file 
                           variable for Songs
* @param[in,out] inRanks - This is the variable has has the input file
                           variable for Ranks
* @param[in] ranks[] - This is the array that holds the ranks that the song has
* @param[in] songs[][81] - This is the array that holds the song name up to 80 
                           characters long
* @param[in] max_elements - This is the variable that holds the maximum array elements 
                            it can hold
*
* @returns i which is the number of elements that were filled in the array
*****************************************************************************/
int readSongsRanks(ifstream &inSongs, ifstream &inRanks, int ranks[], char songs[][81], int max_elements)
{
    max_elements = 100;
    int i = 0;
    while(i < max_elements && inRanks >> ranks[i])
    {
        inSongs.getline(songs[i], 81);
        i++;
    }

    return i;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      This function sorts both the ranks and songs arrays according to the 
*      ranking values, in ascending order. This function returns nothing.
*
* @param[in] ranks[] - This is the array that holds the ranks that the song has
* @param[in] songs[][81] - This is the array that holds the song name up to 80 
                           characters long
* @param[in] numSongs - This holds the number of songs that are being ranked
*
* @returns none
*****************************************************************************/
void sortSongsByRank(int ranks[], char songs[][81], int numSongs)
{
    for (int i = 0; i < (numSongs - 1); i++)
    {
        for (int j = 0; j < (numSongs - 1); j++)
        {
            if(ranks[j] > ranks[j + 1])
            {
                swapIntegers(ranks[j], ranks[j+1]);
                swapCStrings(songs[j], songs[j+ 1]);
            }
             
        }
    }
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*      The function prints the ranks and songs arrays to the file.
*      This function returns nothing.
*
* @param[in,out] out -  This is the variable has has the output file variable
* @param[in] ranks[] - This is the array that holds the ranks that the song has
* @param[in] songs[][81] - This is the array that holds the song name up to 80 
                           characters long
* @param[in] numSongs - This holds the number of songs that are being ranked
*
* @returns none
*****************************************************************************/
void writeList(ofstream &out, int ranks[], char songs[][81], int numSongs)
{
    for (int i = 0; i < numSongs; i++)
    {
        out << ranks[i] << " " << songs[i] << endl;
    }
}

