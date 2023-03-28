/*
CSC 150 Fall 2019
Lab 5 p1002
Amanda Lauen
*/
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cctype>

using namespace std;


int main()
{
    //Declare variables
    char user_input;
    double duck1_amount = 0.0;
    double duck2_amount = 0.0;
    double duck3_amount = 0.0;
    double duck_cost;
    int ducks_in_pond;
    double expected_value;
    char seed_input;
    int lower_bound;
    int upper_bound;
    int fixed_seed_value;
    double rand_value1;
    double rand_value2;
    double rand_value3;

    //Set decimal precision to only 2 places
    cout << fixed << showpoint << setprecision(2);

    cout << "Duck Pond Game Analysis" << endl << endl;
    //Ask the user if they want to manually enter inputs or randomize them
    cout << "Do you want to (e)nter the winning duck amounts" << endl;
    cout << "or (r)andomly generate them? ";
    cin >> user_input;

    //Determines if the user entered letter 'e' (case insentitive)
    if (user_input == 'e' || user_input == 'E')
    {
        //Asks user to enter in ducks 1-3 amounts, cost of ducks, 
        // and total in pond
        cout << "Duck 1 winning amount: $";
        cin >> duck1_amount;
        cout << "Duck 2 winning amount: $";
        cin >> duck2_amount;
        cout << "Duck 3 winning amount: $";
        cin >> duck3_amount;
        cout << "Enter duck cost: $";
        cin >> duck_cost;
        cout << "Enter total number of ducks in pond: ";
        cin >> ducks_in_pond;

        //Calculated expected value to win/lose
        expected_value = ((duck1_amount) * (1.0 / (ducks_in_pond - 3))
                         + ((duck2_amount) * (1.0 / (ducks_in_pond - 3))
                         + ((duck3_amount) * (1.0 / (ducks_in_pond - 3))
                         - ((duck_cost) * ((ducks_in_pond - 3) 
                         / double(ducks_in_pond))))));

        cout << "Expected value: $" << expected_value << endl;
        //Determines if the expected value is positive or negative
        if (expected_value > 0)
        {
            cout << "You should play the duck game" << endl;
        }
        else
        {
            cout << "You should not play the duck game" << endl;
        }
    }

    //Determines if the user inputs letter 'r' case insensitive
    else if (user_input == 'r' || user_input == 'R')
    {
        //Asks user for fixed or time seed
        cout << "(F)ixed seed or (t)ime seed? ";
        cin >> seed_input;
        //Determines if the user chose letter 'f' case insensitive
        if (seed_input == 'F' || seed_input == 'f')
        {
            //Asks user for fixed seed value and bounds between them
            cout << "Enter fixed seed value: ";
            cin >> fixed_seed_value;
            //Set random integer to fixed seed value
            srand((int)fixed_seed_value);
            cout << "Lower bound: ";
            cin >> lower_bound;
            cout << "Upper bound: ";
            cin >> upper_bound;

            //Determines if the upper bound is less than the lower bound
            if (upper_bound < lower_bound)
            {
                cout << "Invalid bounds; please run program again" << endl;
                return 0;
            }
            //Determines if the upper bound is greater than or equal 
            // to  the lower bound
            else if (upper_bound >= lower_bound)
            {
                //Calculates random values for ducks 1-3 amounts
                rand_value1 = rand() % (upper_bound - lower_bound + 1)
                              + lower_bound;
                rand_value2 = rand() % (upper_bound - lower_bound + 1) 
                              + lower_bound;
                rand_value3 = rand() % (upper_bound - lower_bound + 1) 
                              + lower_bound;
                cout << "Duck 1 winning amount: $" << rand_value1 << endl;
                cout << "Duck 2 winning amount: $" << rand_value2 << endl;
                cout << "Duck 3 winning amount: $" << rand_value3 << endl;
                //Asks user for duck cose and number of ducks in the pond
                cout << "Enter duck cost: $";
                cin >> duck_cost;
                cout << "Enter total number of ducks in pond: ";
                cin >> ducks_in_pond;

                //Calculates expected value to win/lose
                expected_value = ((rand_value1) * (1.0 / (ducks_in_pond - 3))
                                 + ((rand_value2) * (1.0 / (ducks_in_pond - 3))
                                 + ((rand_value3) * (1.0 / (ducks_in_pond - 3))
                                 - ((duck_cost) * ((ducks_in_pond - 3)
                                 / double(ducks_in_pond))))));
                cout << "Expected value: $" << expected_value << endl;
                //Determines if the expected value is positive or negative
                if (expected_value > 0)
                {
                    cout << "You should play the duck game" << endl;
                }
                else
                {
                    cout << "You should not play the duck game" << endl;
                }
            }
            //Determines if the bounds are within the range
            else
            {
               cout << "Invalid bounds; please run program again" << endl;
            }

        }
        //Determines if the seed input is 't' case insensitive
        else if (seed_input == 't' || seed_input == 'T')
        {
            //Set time = 0
            srand((int)time(0));
            //Asks the user for the upper and lower bounds
            cout << "Lower bound: ";
            cin >> lower_bound;
            cout << "Upper bound: ";
            cin >> upper_bound;

            //Determines if the upper bound is less than the lower bound
            if (upper_bound < lower_bound)
            {
                cout << "Invalid bounds; please run program again" << endl;
                return 0;
            }
            //Determines if the upper bound is greater than or equal to the lower bound
            else if (upper_bound >= lower_bound)
            {
                //Calculates random values for ducks 1-3 amounts
                rand_value1 = rand() % (upper_bound - lower_bound + 1) 
                              + lower_bound;
                rand_value2 = rand() % (upper_bound - lower_bound + 1) 
                              + lower_bound;
                rand_value3 = rand() % (upper_bound - lower_bound + 1) 
                              + lower_bound;
                cout << "Duck 1 winning amount: $" << rand_value1 << endl;
                cout << "Duck 2 winning amount: $" << rand_value2 << endl;
                cout << "Duck 3 winning amount: $" << rand_value3 << endl;
                //Asks user for the duck cost and total number of ducks
                cout << "Enter duck cost: $";
                cin >> duck_cost;
                cout << "Enter total number of ducks in pond: ";
                cin >> ducks_in_pond;

                //Calculates expected value to win/lose
                expected_value = ((rand_value1) * (1.0 / (ducks_in_pond - 3))
                                 + ((rand_value2) * (1.0 / (ducks_in_pond - 3))
                                 + ((rand_value3) * (1.0 / (ducks_in_pond - 3))
                                 - ((duck_cost) * ((ducks_in_pond - 3) 
                                 / double(ducks_in_pond))))));

                cout << "Expected value: $" << expected_value << endl;
                //Determines if the expected value is positive or negative
                if (expected_value > 0)
                {
                    cout << "You should play the duck game" << endl;
                }
                else
                {
                    cout << "You should not play the duck game" << endl;
                }
            }
            //Determines if the bounds are vailid or not
            else
            {
                cout << "Invalid bounds; please run program again" << endl;
            }
        }

    }
    //Determines if the user input is valid or not
    else
    {
        cout << "Invalid selection; please run program again" << endl;
    }

    //Ends program
    return 0;
}
