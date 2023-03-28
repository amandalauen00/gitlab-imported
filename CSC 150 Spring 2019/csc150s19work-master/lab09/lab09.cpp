#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// do not modify
const string MONTHNAMES[12] = { "January", "February", "March",
        "April", "May", "June", "July", "August", "September", "October",
        "November", "December" };
const int DAYS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


// write prototypes here
void read_temperature(int temps[], int size);
int min_temperature(int temps[], int size);
int max_temperature(int temps[], int size);
double average_temperature(int temps[], int size);

int main()
{
    int month = 0;

    cout << endl << "SDSMT Weather Center" << endl;

    cout << endl;
    cout << "Enter the month (1-12): ";
    cin >> month;

    cout << endl;
    cout << "Enter the highs: ";
    // enter your function call here to read the highs
    int highs[31] = { 0 };
    read_temperature(highs, DAYS[month - 1]);
    
    cout << endl;
    cout << "Enter the lows: ";
    // enter your function call here to read the lows
    int lows[31] = { 0 };
    read_temperature(lows, DAYS[month - 1]);

    // enter your function calls find lowest and average temperature
    int min = min_temperature(lows, DAYS[month - 1]);
    double low_avg = average_temperature(lows, DAYS[month - 1]);

    // enter your function calls find highest and average temperature
    int max = max_temperature(highs, DAYS[month - 1]);
    double high_avg = average_temperature(highs, DAYS[month - 1]);

    cout << fixed << setprecision(1);
    cout << endl;
    cout << "Monthly Report for " << MONTHNAMES[month-1] << endl;
    cout << "Lowest Temperature: " << min << endl;
    cout << "Highest Temperature: " << max << endl;
    cout << "Average Low Temperature: " << low_avg << endl;
    cout << "Average High Temperature: " << high_avg << endl;
    cout << endl;

    return 0;
}

// write your functions here

void read_temperature(int temps[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> temps[i];
    }
}

int min_temperature(int temps[], int size)
{
    int i;
    int min = temps[0];
    for (i = 0; i < size; i++)
    {
        if (temps[i] < min)
        {
            min = temps[i];
        }
    }
    return min;
}

int max_temperature(int temps[], int size)
{
    int i;
    int max = temps[0];
    for (i = 0; i < size; i++)
    {
        if (temps[i] > max)
        {
            max = temps[i];
        }
    }
    return max;
}

double average_temperature(int temps[], int size)
{
    int i;
    int sum = 0;
    double average = 0;
    for (i = 0; i < size; i++)
    {
        sum += temps[i];
    }
    average = double(sum) / size;
    return average;
}