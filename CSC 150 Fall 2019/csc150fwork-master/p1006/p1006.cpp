/** ***************************************************************************
 * @file
 *
 * @brief Calculates best deal on pizza given size and cost
 *
 * @mainpage Lab 8 - Pizza Calculator
 *
 * @section course_section Course Information
 *
 * @authors Amanda Lauen
 *
 * @date October 2019
 *
 * @par Course:
 *         CSC 150
 *
 * @section program_section Program Information
 *
 * @details This program asks the user to enter the size (diameter, in
 * inches) of three sizes of pizza, using a function to get each value.
 * The size names are passed from main
 * into the getDiameter and getCost functions as parameters.
 *
 * Then, the program uses another function to calculate the area of each
 * pizza and return the cost per square inch of each pizza. In the main function,
 * the cost per square inch are compared to find out which pizza size is the
 * best deal.
 *
 * Finally, another function is called to print the results of the best
 * pizza deal, including the pizza diameter, total cost, and cost per
 * square inch.
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @todo Put your name in the doxygen headers
 * @todo Write the function and prototype for getDiameter
 * @todo Write the function and prototype for calcUnitCost
 * @todo Write the function and prototype for printResults
 * @todo Write the function calls for getCost
 * @todo Write the function call for printHeader
 *
 *
 *****************************************************************************/

 /*This statement allows use of M_PI in Visual Studio*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

/*Function Prototypes*/
double getCost(string category);
void printHeader();
int getDiameter(string category);
double calcUnitCost(int pizzaDiameter, double cost);
void printResults(int pizzaDiameter, double costPerSquareInch, double cost);
/*TODO: Add additional function prototypes here*/


/** ***************************************************************************
 * @author K. Corwin and Amanda Lauen
 *
 * @par Description:
 * First, set the output iomanip options to print doubles as money values. Then,
 * call the function to print the welcome message for the program.  Next, call
 * getDiameter and getCost for each of the three size categories of pizza.  Call
 * calcUnitCost for each size of pizza to find the unit cost for each size.
 * Compare the unit costs for each size of pizza to find which is the best
 * deal (lowest cost per unit) and save that pizza's info as "best" cost, size,
 * and unit cost.  Finally, call printResults to print the cost, size, and
 * unit cost for the best pizza deal.
 *
 * @returns 0 - program ran successfully
 *
 *****************************************************************************/
int main()
{
    //Pizza Diameters, in whole inches
    int smallD;
    int medD;
    int largeD;

    //Total cost of each pizza
    double smallCost;
    double medCost;
    double largeCost;

    //Cost per square inch of each pizza
    double smallUnitCost;
    double medUnitCost;
    double largeUnitCost;

    //Store the diameter, total cost, and the cost per square inch
    // for the pizza that is the best deal.
    int bestD;
    double bestCost;
    double bestUnitCost;

    //Set output to 2 decimal places (money)
    cout << fixed << showpoint << setprecision(2);

    //Print header
    /*TODO: Add a function call here to printHeader */

    printHeader();

    //Call the get cost and get diameter functions for each pizza size
    /*TODO: Refer to the getDiameter function calls (DO NOT CHANGE THEM)
     * to write the getDiameter function */
     /*TODO: Add calls to getCost such that the program flow
      * matches the sample runs. */
    smallD = getDiameter("Small");
    smallCost = getCost("Small");
    medD = getDiameter("Medium");
    medCost = getCost("Medium");
    largeD = getDiameter("Large");
    largeCost = getCost("Large");


    //Calculate unit cost for each size
    /*TODO: Refer to these function calls (DO NOT CHANGE THEM)
     * to write the calcUnitCost function*/
    smallUnitCost = calcUnitCost(smallD, smallCost);
    medUnitCost = calcUnitCost(medD, medCost);
    largeUnitCost = calcUnitCost(largeD, largeCost);

    //Find the best deal - cheapest per square inch - and save the data
    // for that pizza.
    if (smallUnitCost <= medUnitCost && smallUnitCost <= largeUnitCost)
    {
        bestD = smallD;
        bestCost = smallCost;
        bestUnitCost = smallUnitCost;
    }
    else if (medUnitCost <= smallUnitCost && medUnitCost <= largeUnitCost)
    {
        bestD = medD;
        bestCost = medCost;
        bestUnitCost = medUnitCost;
    }
    else
    {
        bestD = largeD;
        bestCost = largeCost;
        bestUnitCost = largeUnitCost;
    }

    cout << endl;

    //print the best deal
    /*TODO: Refer to this function call (DO NOT CHANGE IT)
     *  to write the printResults function*/
    printResults(bestD, bestCost, bestUnitCost);

    //Main function always returns 0; means program was successful.
    return 0;
}

/** ***************************************************************************
 * @author K. Corwin
 *
 * @par Description:
 * Prints a prompt for the user to enter the total cost for the pizza in the
 * desired size category, given by the category parameter.  Reads in a double
 * input from the user and returns that value as the total cost for the pizza.
 * No error checking is performed on the user input.
 *
 * @param[in] category - The size category for the pizza (e.g. "small")
 *
 * @returns cost - The total cost of that pizza
 *****************************************************************************/
double getCost(string category)
{
    double cost;
    cout << "Enter cost for " << category << " pizza: $";
    cin >> cost;
    return cost;
}

/** ***************************************************************************
 * @author K. Corwin
 *
 * @par Description:
 * Prints the welcome message for the program followed by a line of dashes.
 *
 * @returns none
 *****************************************************************************/
void printHeader()
{
    cout << "Hardrocker Pizza Comparison Tool" << endl;
    cout << "--------------------------------" << endl << endl;
}

/* TODO: Add the getDiameter function
 * Hint: Take a look at the getCost function -
 *   the two functions will be similar, but not identical.
 *   Also, copy text from p1006-messages.txt.
 */
int getDiameter(string category)
{
    int pizzaDiameter;
    cout << "Enter diameter for " << category << " pizza: ";
    cin >> pizzaDiameter;
    return pizzaDiameter;

}



 /* TODO: Add the printResults function
  * Hint: Copy text from p1006-messages file */
void printResults(int pizzaDiameter, double cost, double costPerSquareInch)
{
    cout << "Best deal is the " << pizzaDiameter << "\" pizza." << endl;
    cout << "Total cost: $" << cost << endl;
    cout << "Cost per square inch: $" << costPerSquareInch << endl;
}



  /* TODO: Add the calcUnitCost function
  * Hint: This function should calculate the area
  *  using "pi r squared" formula,
  *  then calculate and return cost per square inch */
double calcUnitCost(int pizzaDiameter, double cost)
{
    double costPerSquareInch;
    costPerSquareInch = cost / (M_PI * pow((pizzaDiameter / 2.0), 2.0));
    return costPerSquareInch;
}


