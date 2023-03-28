/*
    p1009 Lab 11
    CSC 150 Fall 2019
    2D Population Grid analysis
    NAME: Amanda Lauen
 */

#include <iostream>
#include <iomanip>

using namespace std;

void getMaxPopAndLocation(int populations[][20], int rows, int cols,
    int &maxRowLocation, int &maxColLocation, int &totalPop);
void printResults(int row, int col, int totalPop);
//TODO: Add more prototypes
void printGrid(int population[][20], int row, int col);
void getPopulations(int population[][20], int row, int col, int row_loc, int col_loc);
int findMetroPop(int populations[][20], int row, int col, int row_loc, int col_loc);

int main()
{
    //TODO: declare the 2D array

    int population[20][20];

    //Number of rows and columns to fill
    int rows, cols;

    //Maximum population value and its central location
    int maxR = 0;
    int maxC = 0;
    int maxPop = 0;

    //ask user for size of grid
    cout << "How many rows in population grid? ";
    cin >> rows;
    cout << "How many columns in population grid? ";
    cin >> cols;

    //TODO: add function calls to perform each task:

    //fill grid
    getPopulations(population, rows, cols, maxR, maxC);
    getMaxPopAndLocation(population, rows, cols,
        maxR, maxC, maxPop);

    //print grid to make sure it is read in properly
    printGrid(population, rows, cols);

    //find highest metro area population and its center location
    findMetroPop(population, rows, cols, maxR, maxC);

    //print results
    printResults(maxR, maxC, maxPop);

    return 0;
}

/** ***************************************************************************
 * @author K Corwin
 *
 * @par Description:
 * This function takes in the entire population array (up to 20x20),
 * 	and	the number of rows and columns that are filled in the array.
 *
 * This function calls the findMetroPop function on each filled element,
 * to find the metro population total for that element plus each adjacent
 * element.
 *
 * This function runs the find max algorithm on the metro population values.
 * When the max is found, the central location of that maximum is also saved.
 *
 * The function provides back the maximum metro population plus its row and
 * column location.
 *
 * @param[in] populations - 2D array containing populations
 * @param[in] rows - the number of filled rows in the populations array.
 * @param[in] cols - the number of filled columns in the populations array.
 * @param[out] maxRowLocation - the row index of the center of the maximum
 * 								metro population
 * @param[out] maxColLocation - the column index of the center of the maximum
 * 								metro population
 * @param[out] maxSoFar - when the function is completed, this will contain
 * 							the maximum metro population value
 *
 *****************************************************************************/
void getMaxPopAndLocation(int populations[][20], int rows, int cols,
    int &maxRowLocation, int &maxColLocation, int &maxSoFar)
{
    //metroPop is a sum, so must initialize to zero.
    int metroPop = 0;

    //Initialize max value to the first population value
    maxSoFar = populations[0][0];

    //Initialize max location to the first element
    maxRowLocation = 0;
    maxColLocation = 0;

    //Find the location of the largest metro area
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //TODO: Call findMetroPop
            metroPop = findMetroPop(populations, rows, cols, i, j);

            //Max algorithm, but also
            // save the location it's found in
            if (metroPop > maxSoFar)
            {
                maxSoFar = metroPop;
                maxRowLocation = i;
                maxColLocation = j;
            }
        }
    }
}

/** ***************************************************************************
 * @author K Corwin
 *
 * @par Description:
 * This function prints the highest metro population and its location
 * (row and column indexes for the center element of the highest metro
 * population) on the screen in an informative message.
 *
 * @param[in] row - the row index of the center of the maximum
 * 								metro population
 * @param[in] col - the column index of the center of the maximum
 * 								metro population
 * @param[in] totalPop - the maximum metro population value
 *
 *****************************************************************************/
void printResults(int row, int col, int totalPop)
{
    cout << "The most populous metro area is centered at ("
        << row << ", " << col << ")" << endl
        << "with a population of "
        << totalPop << endl;
}

void printGrid(int population[][20], int row, int col)
{
    int i;
    int j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << setw(8) << population[i][j];
        }
        cout << endl;
    }
}

void getPopulations(int populations[][20], int row, int col, int row_loc, int col_loc)
{
    int i;
    int j;
    cout << "Enter population values: ";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> populations[i][j];
        }
    }
    cout << endl;
}

int findMetroPop(int populations[][20], int row, int col, int row_loc, int col_loc)
{
    int i;
    int j;
    int metroPop = 0;
    
    //Nested loops
    for (i = (row_loc - 1); i <= (row_loc + 1); i++)
    {
        
        for (j = (col_loc - 1); j <= (col_loc + 1); j++)
        {
            if ((i < row) && (j < col) && (i >= 0) && (j >= 0))
            {
                metroPop = metroPop + populations[i][j];
            }

        }
    }
    
    return metroPop;
}

