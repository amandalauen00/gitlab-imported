#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int getNumSongs();
void getSongData(int &curr_rating, int &prev_rating);
void getRiseDecline(int num_songs, int &num_risen, int &num_declined);
void printResults(int num_risen, int num_declined);

int main()
{
    int songs;
    int num_rise = 0;
    int num_dec = 0;
    
    songs = getNumSongs();
    getRiseDecline(songs, num_rise, num_dec);
    printResults(num_rise, num_dec);
    return 0;
}


int getNumSongs()
{
    int num_songs;
    cout << "How many songs would you like to enter? ";
    cin >> num_songs;
    while (num_songs < 1)
    {
        cout << "How many songs would you like to enter? ";
        cin >> num_songs;  
    }
    return num_songs;
}

void getSongData(int &curr_rating, int &prev_rating)
{
    cout << "Enter song's rank: ";
    cin >> curr_rating;
    cout << "Enter song's previous rank: ";
    cin >> prev_rating;
}

void getRiseDecline(int num_songs, int &num_risen, int &num_declined)
{
    int i;
    int curr_rating;
    int prev_rating;
    for (i = 0; i < num_songs; i++)
    {
        
        getSongData(curr_rating, prev_rating);
        if (curr_rating < prev_rating)
        {
            num_risen = num_risen + 1;
        }
        else if (curr_rating > prev_rating)
        {
            num_declined = num_declined + 1;
        }
        else
        {
            continue;
        }
    }
   
}

void printResults(int num_risen, int num_declined)
{
    cout << endl;
    cout << num_risen << " songs have risen this week" << endl
    << "and " << num_declined << " songs have declined this week." << endl;
}
