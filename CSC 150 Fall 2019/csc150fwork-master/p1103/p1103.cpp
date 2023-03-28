#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int get_Random(int lower_limit, int upper_limit);
void print_Result(int guess, int goal, int count);

int main()
{
    int low_limit;
    int up_limit;
    int guess;
    int goal;
    int count = 1;

    srand(600);

    cout << "Lower limit: ";
    cin >> low_limit;
    cout << "Upper limit: ";
    cin >> up_limit;

    while (up_limit < low_limit)
    {
        cout << "Try again." << endl;
        cout << "Lower limit: ";
        cin >> low_limit;
        cout << "Upper limit: ";
        cin >> up_limit;
    }
    
    goal = get_Random(low_limit, up_limit);
    cout << "Enter first guess: ";
    cin >> guess;

    while ((guess != goal) && (count < 5))
    {
        count++;
        cout << "Incorrect!" << endl;
        if (count < 6)
        {
            cout << "Enter next guess: ";
            cin >> guess;
        }
    }
    print_Result(guess, goal, count);

    return 0;
}

int get_Random(int lower_limit, int upper_limit)
{
    int my_Rand;
    my_Rand = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    
    return my_Rand;
}

void print_Result(int guess, int goal, int count)
{
    if (guess == goal)
    {
        cout << "You won in " << count << " guesses!" << endl;
    }
    else
    {
        cout << "You lost. The number was " << goal << endl;
    }
}
