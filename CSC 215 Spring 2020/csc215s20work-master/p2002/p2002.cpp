#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    long long int num;
    //long long int curr_num;
    long long int min;
    long long int count = 0;
    long long int max;
    long long int sum = 0;
    double average = 0.0;
    
    cout << fixed << setprecision ( 4 );
    
    min =  numeric_limits < long long int >::max();
    max =  numeric_limits < long long int >::min();
    
    cout << "Enter a number: ";
    
    while ( cin >> num )
    {
        cout << endl;
        
        count++;
        cout << "Count: " << count << endl;
        
        
        if ( num > max )
        {
            max = num;
        }
        if ( num < min )
        {
            min = num;
        }
        



        cout << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
        
        sum += num;
        cout << "Sum: " << sum << endl;
        
        average = double ( sum ) / count ;
        cout << "Average: " << average  << endl;
        
        cout << endl << "Enter a number: ";
    }
    
    
    return 0;
}