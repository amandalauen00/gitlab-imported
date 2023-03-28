#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

int main ( int argc, char **argv )
{
    ofstream fout1;

    // Validate that arguments were supplied on startup
    if ( argc != 4 )
    {
        cout << "Usage p2030.exe seed quantity filename";
        return 0;
    }

    char *myseed = argv[1];
    char *count = argv[2];

    //Convert C strings to integers
    int curr_count = atoi(count);
    int curr_seed = atoi (myseed);

    //Open files
    fout1.open(argv[3]);

    if (!fout1.is_open())
    {
      cout << "Unable to open file: " << argv[3] ;
      return 0;
    }
    
    //Dynamically allocate memory
    int *mem_address;
    mem_address = new (nothrow) int [curr_count];
    if (mem_address == nullptr)
    {
        cout << "Unable to allocate memory" << endl;
    }
    
    //Populate array w/ random numbers
    default_random_engine generator;
    uniform_int_distribution<int> distribution ( -1000000, 1000000);
    generator.seed(curr_seed);

    for (int i = 0; i < curr_count; i++)
    {
        mem_address[i] = distribution(generator);
    }
    
    //Sort the array
    sort(mem_address, mem_address + curr_count);
    
    //Output the file
    if(fout1.is_open())
    {
        fout1 << curr_count << endl;
        for (int i = 0; i < curr_count; i++)
        {
            if((i != 0 && ((i % 4 == 0))))
            {
               fout1 << endl;
            }
            fout1 << right;
            fout1 << setw(15);
            fout1 << mem_address[i];
            fout1 << setw(15);
        }
        fout1 << endl;
    }

    //Clean up
    fout1.close();
    delete[] mem_address;

    return 0;
}
