/*
    CSC 150 Lab 13 Fall 2019
    Practice with input and output files
        and command line options
    NAME: Amanda Lauen
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

//TODO: add appropriate #includes

using namespace std;

//TODO: add prototypes
void readScores(ifstream &inFile, double scores[], int num_elements);
void readNames(ifstream &inFile, char name[][81], int num_elements);
void printRecordsToFile(ofstream &outFile, double scores[], char names[][81], int num_elements);


//TODO: modify the int main() header to accept command line arguments
int main(int argc, char* argv[])
{
    //TODO: declare input and output file object variables
    ifstream inFile;
    ofstream outFile;
    
    //TODO: declare arrays and other variables as needed

    double scores[100];
    char name[100][81];
    int num_elements = 0;

    outFile << fixed << showpoint << setprecision(3);
    //TODO: Before we do anything else, 
    // we must do the error check on number of command line arguments.
    // If the wrong number of arguments is present, print message and end program.
    //NOTE: Gitlab requires a return 0 (not return 1, etc.)
    if (argc != 3)

    {
        cout << "Usage: p1013.exe <in filename> <out filename>" << endl;
        return 0;
    }


    //TODO: Attempt to open both files.
    inFile.open(argv[1]);
    outFile.open(argv[2]);

    //TODO: Again, before we try to access the files,
    // we must perform an error check on the files
    // successfully opening.
    //If _either_ of the files did not successfully open, print the error message
    // and end the program with return 0.
    //     
    if(!inFile.is_open() || !outFile.is_open())
    {
        cout << "File opening error; program ending" << endl;
        return 0;
    }

    //TODO: Read/store first value from the file (number of records)
    inFile >> num_elements;


/*----- Complete the main function up to this point in lab period ------------*/
/*----- At this point, have your above code checked off before proceeding-----*/

    //TODO: Call function to read in the scores

    readScores(inFile, scores, num_elements);

    //Because we are switching between reading numbers
    // and reading lines, there is a newline
    // left in the buffer. This code will skip over the extra 
    // newline, so we can get on to reading in the names.
    inFile.ignore();

    //TODO: Call function to read in the names

    readNames(inFile, name, num_elements);

    //TODO: Call function to print the new file
    printRecordsToFile(outFile, scores, name, num_elements);

    //TODO: remember to close both files!
    inFile.close();
    outFile.close();


    return 0;
}

//TODO: add function definitions here

void readScores(ifstream &inFile, double scores[], int num_elements)
{
    for (int i = 0; i < num_elements; i++)
    {
        inFile >> scores[i];
    }
    
}

void readNames(ifstream &inFile, char name[][81], int num_elements)
{
        for (int i = 0; i < num_elements; i++)
        {
            inFile.getline(name[i], 81);
        }
}

void printRecordsToFile(ofstream &outFile, double scores[], char names[][81], int num_elements)
{
    for (int i = 0; i < num_elements; i++)
    {
         outFile << names[i] << " :" << scores[i] << endl;
    }
}