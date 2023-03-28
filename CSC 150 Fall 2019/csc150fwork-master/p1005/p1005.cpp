/*
CSC 150 Fall 2019
Lab 6 p1005
Amanda Lauen
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //Declare variables
    //Dark square on dark screen
    char dark = char(176);
    //Light square on dark screen
    char light = char(178);
    int user_rows;
    int user_columns;
    int i;
    int j;

    //Ask user for rows they want
    cout << "Rows: ";
    cin >> user_rows;

    //Ask user for columns they want
    cout << "Columns: ";
    cin >> user_columns;

    
    for (i = 0; i < user_rows; i++)
    {
        //Determine which color each block is
        for (j = 0; j < user_columns; j++)
        {
            if ((i % 2 == 0 && j % 2 == 0) ||(i % 2 == 1 && j % 2 == 1))
            {
                cout << dark;
            }
            else
            {
                cout << light;
            }
        }
        cout << endl;
    }
    
    //Ends program
    return 0;
}