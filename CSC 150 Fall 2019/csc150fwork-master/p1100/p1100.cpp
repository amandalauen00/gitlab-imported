/*
* Duck Pond Expected Value
* Version 2: uses functions
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRand(int lowerBound, int upperBound);
/* TODO: Add your prototype here for the new function that calculates expected value */

int main()
{
    double duck1win, duck2win, duck3win;
    double duckCost;
    double expectedValue;
    int totalDucks;
    char userChoice;
    int lower, upper;

    int seedValue;
    char seedType;

    //set up money output
    cout << fixed << showpoint << setprecision(2);

    cout << "Duck Pond Game Analysis" << endl << endl;

    cout << "Do you want to (e)nter the winning duck amounts" << endl
        << "or (r)andomly generate them? ";
    cin >> userChoice;

    //convert userChoice to lowercase (uppercase is ok)
    userChoice = tolower(userChoice);

    if (userChoice == 'r')
    {
        //select fixed or random seed
        cout << "(F)ixed seed or (t)ime seed? ";
        cin >> seedType;

        seedType = tolower(seedType);

        if (seedType == 'f')
        {
            cout << "Enter fixed seed value: ";
            cin >> seedValue;
            srand(seedValue);
        }
        else
        {
            //seed random
            srand((int)time(0));
        }

        //ask for lower and upper bounds
        cout << "Lower bound: ";
        cin >> lower;
        cout << "Upper bound: ";
        cin >> upper;

        //another error check
        if (lower > upper)
        {
            cout << "Invalid bounds; please run program again" << endl;
            return 0;
        }

        //generate duck values randomly (as integers)
        /* TODO: Add function calls here to get the values of duck1win, duck2win, duck3win */



        //print them on the screen, so we can see them
        cout << "Duck 1 winning amount: $" << duck1win << endl;
        cout << "Duck 2 winning amount: $" << duck2win << endl;
        cout << "Duck 3 winning amount: $" << duck3win << endl;

    }
    else if (userChoice == 'e')
    {
        //ask for duck values
        cout << "Duck 1 winning amount: $";
        cin >> duck1win;
        cout << "Duck 2 winning amount: $";
        cin >> duck2win;
        cout << "Duck 3 winning amount: $";
        cin >> duck3win;

    }
    else
    {
        cout << "Invalid selection; please run program again" << endl;
        return 0;
    }

    //next, get the cost of each duck and total number of ducks
    cout << "Enter duck cost: $";
    cin >> duckCost;
    cout << "Enter total number of ducks in pond: ";
    cin >> totalDucks;

    //now that we have the duck values, calculate the 
    // expected value from playing the game
    //New function call!
    /* TODO: Refer to this function call to write your new function */
    double calcExpectedValue()
    {
        
        
        return expectedValue;
    }
    expectedValue = calcExpectedValue(duck1win, duck2win, duck3win,
        duckCost, totalDucks);

    //print out expected value
    cout << "Expected value: $" << expectedValue << endl;

    if (expectedValue > 0)
    {
        cout << "You should play the duck game" << endl;
    }
    else
    {
        cout << "You should not play the duck game" << endl;
    }

    return 0;
}

//New function: generate a random integer between a lower bound and upper bound
/*TODO: Refer to this function header to write the needed function calls in main*/
int generateRand(int lowerBound, int upperBound)
{
    int randomNum;
    randomNum = rand() % (upperBound - lowerBound + 1) + lowerBound;
    return randomNum;
}

/*
Removed code that calculated expected value:

expectedValue = duck1win * (1.0 / (totalDucks - 3))
    + duck2win * (1.0 / (totalDucks - 3))
    + duck3win * (1.0 / (totalDucks - 3))
    - duckCost * ((totalDucks - 3) / (double)totalDucks);
*/

/*TODO: Add new function here to calculate expected value*/
