/*
Mini Lab on Struct and Search
CSC 150 Fall 2019
Based on Lab 14 - Files, Command line,
Sorting - Song Rankings, Revisited

NAME: Amanda Lauen
*/

//This define is needed to avoid Visual Studio cstring function warnings
#define _CRT_SECURE_NO_WARNINGS
#include <fstream> 
#include <iostream>

using namespace std;

//TODO: Define a Song data type
struct Song
{
    int rank;
    char title[81];

};

void sortSongsByRank(Song songs[], int count);
int readSongsRanks(ifstream &inSongs, ifstream &inRanks,
    Song songs[], int max);

//TODO: add new function prototype
int binarySearchRank(Song songs[], int rank, int numSongs);

int main(int argc, char* argv[])
{
    ifstream inSongs;
    ifstream inRanks;
    int numSongs;
    int user_rank;
    int rank_value;

    //TODO: declare array to hold up to 100 Songs
    Song songs[100];

    //Check argc before doing anything else.
    if (argc != 3)
    {
        cout << "Usage: p1014.exe <song filename> <rank filename>" << endl;
        return 0;
    }

    //now try to open files
    inSongs.open(argv[1]);
    inRanks.open(argv[2]);

    //check to see if files did not open correctly.
    if (!inSongs || !inRanks)
    {
        cout << "File error; program exiting." << endl;
        return 0;
    }

    //read from files
    numSongs = readSongsRanks(inSongs, inRanks, songs, 100);

    //sort songs by rank
    sortSongsByRank(songs, numSongs);

    //TODO: Ask the user which rank they want to find
   
    cout << "Enter a rank: ";
    cin >> user_rank;

    //TODO: search for that rank
    
    rank_value = binarySearchRank(songs, user_rank, numSongs);
    int location = binarySearchRank(songs, user_rank, numSongs);
    //output results
    //TODO: finish this if statement
    if (location == -1)
    {
        //TODO: finish this cout statement - search target not found
        cout << "A song with rank " <<  user_rank   << " was not found." << endl;
    }
    else
    {
        //TODO: finish this cout statement - search target was found
        cout << "A song with rank " <<  user_rank   << " was found at location " << location
            << " and is called "  << songs[rank_value].title << endl;
    }

    //close all files
    inSongs.close();
    inRanks.close();

    return 0;
}

void sortSongsByRank(Song songs[], int count)
{
    //simplest bubble sort
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (songs[j].rank > songs[j + 1].rank)
            {
                //swap the structs
                Song temp = songs[j];
                songs[j] = songs[j + 1];
                songs[j + 1] = temp;
            }
        }
    }
}

int readSongsRanks(ifstream &inSongs, ifstream &inRanks,
    Song songs[], int max)
{
    int i = 0;

    while (i < max &&
        inRanks >> songs[i].rank)
    {
        inSongs.getline(songs[i].title, 81);
        i++;
    }

    return i;
}

//TODO: add binarySearchRank function
int binarySearchRank(Song songs[], int rank, int numSongs)
{
    int left = 0;
    int right = numSongs - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (songs[mid].rank == rank)
        {
            return mid;
        }
        if (songs[mid].rank < rank)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
   return -1;
}