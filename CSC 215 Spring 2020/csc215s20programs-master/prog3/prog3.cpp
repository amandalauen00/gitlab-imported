/** **************************************************************************
 * @file
 ****************************************************************************/
 /** **************************************************************************
 * @mainpage Program 3 - The Knights Tour
 *
 * @section course_section Course Information
 *
 * @authors Amanda Lauen
 *
 * @par Professor:
 *      Roger Schrader
 *
 * @par Course:
 *      CSC215 - M002 - Programming Techniques
 *
 * @par Location:
 *      Classroom Building - Room 118
 *
 * @date Due May 1st, 2020
 *
 * @section program_section Program Information
 *
 * @details
 * This program solves the knight's tour on the chessboard.  The program first
 *  prompts for the command line.  If the incorrect amount of command lines are
 *  entered, an error message is presented and exits the program. 
 *  If the command lines is equal is 1, then the program presents the main menu 
 *  to the user with the options of changing the board size, starting 
 * coordinates, and exiting by solving the tour.  The user then enters their 
 * choice.
 *
 * If the user enters 1, then they enter in the size of board they want which 
 * has to be greater than 3.  If less than 3, then an error message is prompted 
 * and asks the user for a new size of the board again.  If the new size of the 
 * board is less than or equal to the rows and columns, then the program will 
 * prompt the user an error message and tell them to change the coordinates to 
 * have it valid within the board.  
 *
 * If the user enters a 2, then the user is prompted to enter their new 
 * coordinates with it being in the form of [rows, cols.  If the rows and 
 * columns are less than 0 or greater than 7, then an error message is printed 
 * and prompts the user for new starting coordinates.  If the rows and columns 
 * are greater than or equal to the new size of the board, then the program 
 * will output an invalid message and will tell the user to enter a new board 
 * size in order to work with the coordinates entered.
 *
 * If the user enters 3, then the loop is broken, and it will output the solved 
 * tour using the new board size and rows and columns.  To do this, the program 
 * dynamically allocates two 2D arrays of solution and used.  Then the board 
 * will solve the tour using the solveTour function and will output the 
 * solution or "No solution for this case." to the screen formatted neatly with
 * information in the columns.
 *
 * If any other value besides 1, 2, or 3 is entered, then the program outputs 
 * an invalid option message and prompts the user with the menu again.  This 
 * option then frees the arrays of solution and used and returns 0 when ran 
 * successful.
 *
 * If the command line is greater than or equal to 2, then a file is present in 
 * the command line.  The program then opens this input file and checks if it 
 * has opened or not.  It also opens the output file of "Solutions.tours" and 
 * sees if it opened properly.  For both files, if they do not open properly, 
 * then an error message is outputted, and the program exits with return 0.  
 * The program then reads in the input file data until the end of the file.  
 * When all the data is ran in, then the program dynamically allocates two 2D 
 * arrays of solution and used.  Then the board will solve the tour using the 
 * solveTour function and will output the solution or "No solution to this 
 * case." to the output file in  the proper file format.  In this format, the 
 * number of tours car more than 1 so the number of tours is incremented 
 * throughout each tour.  When all the tours are solved, then the program frees 
 * the arrays of solution and used.  It then closes both files and returns 0 
 * when ran successfully.
 *
 * @section compiling_section Compiling and Usage
 *
 * @par Compling Instructions:
 *      none - a straight compile and link with no external libraries.
 *
 * @par Usage:
   @verbatim
   c:\> prog3.exe
   c:\> prog3.exe inputFile
                  inputFile - Holds the file that needs to be input.
   @endverbatim
 *
 * @par Modifications and Development Timeline:
 * <a target="_blank"
 * href="https://gitlab.mcs.sdsmt.edu/7452203/csc215s20programs/-/commits/master">Click Here </a>
 *
 ***************************************************************************/
#include "menu.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int **dynamic_array(int rows, int cols);
bool solveTour(int **solution, int **used, int max_size, int pos_rows,
    int pos_cols, int curr_space);
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
* This function declares all of the variables necessary. It will ensure the
* correct number of command line arguments and will output an error message if
* there is not. It determines if the command line has a file or not. If not,
* then the function prints the main menu.  The menu takes in the user input and
* directs it to the function it needs error checking on the way.  If no valid
* input is entered, then an error message will then be prompted and will
* reprint the menu until a valid option is entered.  This function then frees
* up the 2d arrays and ends the program.  If a file is present in the command
* line argument, it opens the file and ensures it will open. Then the function
* checks to see if it exists and then reads in the data from the file.  The
* data inside the input file is then used to solve the tours given.  The 
* solutions are then outputted to the output file "Solutions.tour". The program
* then closes the input and output files and ends with return 0 when ran 
* successully.
*
* @param[in]   argc - a count of the command line arguments used to start
*                       the program.
* @param[in]   argv - a 2D character array of each argument.  Each token
*                       occupies one line in the array.
*
* @returns 0 program ran successful.
*
***************************************************************************/
int main(int argc, char **argv)
{
    //Initilize variables
    ifstream fin;
    ofstream fout;
    int userNum = 0;
    int new_size = 8;
    int rows = 7;
    int cols = 7;
    int num_tour = 1;
    int **used = NULL;
    int **solution = NULL;
    int max_size = 64;
    int curr_space = 1;

    //Check the command lines
    if (argc < 1 || argc > 3)
    {
        cout << "Incorrect number of command lines, exiting program" << endl;
        cout << "Usage: prog3.exe <filename> (Optional)";
        return 0;
    }

    //If menu is required
    if (argc == 1)
    {
        //Print main menu
        while (userNum != 3)
        {

            cout << "1) Change Board Size from " << new_size << "x" << new_size
                << endl;
            cout << "2) Change starting location from " << "[" << rows << ","
                << cols << "]" << endl;
            cout << "3) Exit and Solve Tour" << endl;
            cout << "Enter Choice: ";
            cin >> userNum;
            cout << endl;

            //If user enters one, then they enter in their size of the board
            if (userNum == 1)
            {
                cout << "Enter the size of the NxN Board (> 3): ";
                cin >> new_size;

                while (new_size < 3)
                {
                    cout << "Invalid value, try again" << endl;
                    cout << "Enter the size of the NxN Board (>3): ";
                    cin >> new_size;
                }

                cout << endl;

                if (new_size <= rows || new_size <= cols)
                {
                    cout << "Invalid board size, please change coordinates"
                        << endl << endl;
                }

            }

            //If the user enters 2, then they enter in new coordinates
            else if (userNum == 2)
            {
                cout << "Enter Starting Coordinates [ row, col ]: ";
                cin >> rows >> cols;

                while (rows < 0 && rows > 7 && cols < 0 && cols > 7)
                {
                    //Update menu to recieve new coords (Ex: [2,4])
                    cout << "Invalid values, try again" << endl;
                    cout << "Enter Starting Coordinates [ row, col ]: ";
                    cin >> rows >> cols;
                }

                cout << endl;

                if (rows >= new_size || cols >= new_size)
                {
                    cout << "Invalid coordinates, please change size" << endl
                        << endl;
                }
            }

            //If the user enters 3, it prints out the board and solves tour
            else if (userNum == 3)
            {
                cout << "Tour #" << num_tour << endl;
                cout << "        " << new_size << "x" << new_size <<
                    " starting at (" << rows << "," << cols << ")" << endl;
                cout << endl;

                max_size = new_size * new_size;
                //Dynamically allocate 2d array and ititilize board
                solution = dynamic_array(new_size, new_size);
                used = dynamic_array(new_size, new_size);

                //Print board and solve tour
                if (solveTour(solution, used, max_size, rows + 2,
                    cols + 2, curr_space) == true)
                {
                    //Output the solution or "No solution" to the screen
                    //formatted neatly w/ information in the columns
                    for (int i = 2; i < new_size + 2; i++)
                    {
                        cout << "        ";

                        for (int j = 2; j < new_size + 2; j++)
                        {

                            cout << setw(4);
                            cout << solution[i][j];
                            cout << setw(4);
                        }
                        cout << endl;
                    }
                }
                else
                {
                    cout << "         " << "No solutions for this case."
                        << endl;
                }
            }

            //If invalid option is entered, output error message and prompt
            //user again
            else
            {
                cout << "Invalid option" << endl;
            }
        }

        //Free the array
        delete solution;
        delete used;
    }

    //If file is given
    else if (argc >= 2)
    {
        //Open file
        fin.open(argv[1]);

        //Check if opened
        if (!fin.is_open())
        {
            cout << "Unable to open file: " << argv[1];
            return 0;
        }

        fout.open("Solutions.tours");

        //Check to see if it opened
        if (!fout.is_open())
        {
            cout << "Unable to open file: Solutions.tours";
            return 0;
        }

        //If the file exists
        while (fin)
        {
            //Read in the first tours
            while (!fin.eof())
            {
                fin >> new_size;
                fin >> rows >> cols;

                //Dynamically allocate 2d array and ititilize board
                solution = dynamic_array(new_size, new_size);
                used = dynamic_array(new_size, new_size);

                //Solve the tour using the brute force backtracking method
                fout << "Tour #" << num_tour << endl;
                fout << "        " << new_size << "x" << new_size <<
                    " starting at (" << rows << "," << cols << ")" << endl;
                fout << endl;

                max_size = new_size * new_size;

                if (solveTour(solution, used, max_size, rows,
                    cols, curr_space) == true)
                {
                    //Output the solutuion or "No solution" in the proper
                    //format to the file
                    for (int i = 2; i < new_size + 2; i++)
                    {
                        fout << "        ";
                        for (int j = 2; j < new_size + 2; j++)
                        {
                            fout << setw(4);
                            fout << solution[i][j];
                            fout << setw(4);
                        }
                        fout << endl;
                    }
                    num_tour++;
                }
                else
                {
                    fout << "         " << "No solutions for this case."
                        << endl;
                    num_tour++;
                }
                //Free the array
                delete solution;
                delete used;
            }
        }
    }
    //Close files
    fin.close();
    fout.close();

    //Exit program
    return 0;

}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
* This function dynamically allocates a 2d array of pointers that is used
* throughout the program.  The function starts by identifying if the pointer
* is equal to null pointer or not for the rows.  If so, then an error message
* is printed and the function is exited.  If not, then the function checks to
* see if the pointer is equal to the null pointer for the columns.  If so, then
* an error message is printed and the function is exited. If not, then the
* function creates the padding rows using the for loop.  The function returns
* the pointer back to int main when it is ran successfully.
*
* @param[in]   rows - Holds the amount of rows used in the program
* @param[in]   cols - Holds the amount of columns used in the program
*
* @returns ptr when function ran successfully.
*
***************************************************************************/
int **dynamic_array(int rows, int cols)
{
    //Initilize variables
    int **ptr = NULL;
    int i;
    int j;
    //Initilize pointer to rows variable
    ptr = new (nothrow) int *[rows + 4];

    //Dynamically allocate for rows
    if (ptr == nullptr)
    {
        cout << "Unable to allocate memory";
        exit(0);
    }

    for (i = 0; i < rows + 4; i++)
    {
        //Initilize pointer of i to the columns variable
        ptr[i] = new (nothrow) int[cols + 4];

        //Dynamically allocate for columns
        if (ptr[i] == nullptr)
        {
            cout << "Unable to allocate memory";
            exit(0);
        }

        //Create padding rows and columns around the game board
        for (j = 0; j < cols + 4; j++)
        {
            if (i <= 1 || i >= rows + 2 || j <= 1 || j >= cols + 2)
            {
                ptr[i][j] = -1;
            }
            else
            {
                ptr[i][j] = 0;
            }


        }
    }

    //Return pointer
    return ptr;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*  This function recursively solves the tour by checking if the max_size is
*  equal to the current space the knight is on the board.  If so, then the 
*  function returns true.  If not, then the function recursively goes through
*  each of the possible 8 ways to move in order to fill the board up.  The 
*  function returns the variable solved (a bool variable) when the function
*  runs successfully.
*
* @param[in]   **solution -  Holds the new solution of the board
* @param[in]   **used -      Holds the spots that are used on the board
* @param[in]   max_size -    Holds the max size of the board
* @param[in]   pos_rows -    Holds the current row on the board
* @param[in]   pos_cols -    Holds the current column on the board
* @param[in]   curr_space -  Holds the current space on the board
*
* @returns solved when functions is ran successfully.
*
***************************************************************************/
bool solveTour(int **solution, int **used, int max_size, int pos_rows,
    int pos_cols, int curr_space)
{
    //Initilize variables
    int i;
    bool solved = false;
    int horizontal_moves[8] = { 2, 1, -2, 1, -1, -2, -1, 2 };
    int vertical_moves[8] = { 1, 2, 1, -2, 2, 1, -2, -1 };

    //Check to see if the current space is at the max size
    if (max_size == curr_space)
    {
        return true;
    }

    //Recursively iterate the board to get new values
    for (i = 0; i < 8; i++)
    {
        if (used[pos_rows][pos_cols] == 0)
        {
            solution[pos_rows][pos_cols] = curr_space;
            used[pos_rows][pos_cols] = -1;
            

            solved |= solveTour(solution, used, max_size, 
                horizontal_moves[i] + pos_rows, vertical_moves[i] + pos_cols, 
                curr_space + 1);

            used[pos_rows][pos_cols] = 0;
        }
        
    }

    //Returned solved
    return solved;
}


