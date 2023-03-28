/** ***************************************************************************
* @file
*
* @mainpage Program 1 - Water and Sewer System
*
* @section course_section Course Information
*
* @author Amanda Lauen
*
* @date September 20th, 2019
*
* @par Professor
*      Kelly Corwin
*
* @par Course
*      CSC150 - M003 - 3:00pm
*
* @par Location
*      Classroom Building - Room 328
*
* @section program_section Program Information
* This program will calculate the user's fees for water and sewer 
* via the Water Bill Estimation Tool.  The program will first prompt 
* the user with the message of "Welcome to the Water Bill Estimation Tool!" and
* ask the user for their name.  Once the user enters their name (with no 
* spaces), the program will prompt the user and ask for the value of their 
* previous water bill.  After that amount is entered, the program will ask for
* the number of days late in payment of the previous bill.  Once that value is
* entered, the program will ask for the previous month water meter reading. 
*
* After that measurement is entered, the program will finally as for 
* the current month water meter reading. After all the information is entered
* into the program, the program will compile the information in the form of 
* equations to calculate the user's water bill.  By calculating the total water
* consumption, the total sewer consumption, the water consumption subtotal, the
* sewer subtotal, and late fees, it will all add together to get the final 
* utility bill total.
*
* Once the totals have been calculated, the program will output the final end 
* menu, which shows the water consumption and the subtotal of it, the sewer 
* consumption and the subtotal of it, the late fees, and will show the total
* at the bottom of the menu.  The program will end with the message "Good bye,
* (user's name)!"  The program will officially end when the user hits any key 
* to exit the program.
*
* @section compiling_section Compiling and Usage
*
* @verbatim
  c:\> prog1.exe
  d:\> c:\bin\prog1.exe
  @endverbatim
*
* @section todo_bugs_modifications_section Todo, Bugs, and Modifications
*
* @bug Description for doxygen doesn't work.
*
* @todo None.
*
* <a href = "https://gitlab.mcs.sdsmt.edu/7452203/csc150fprograms/
  commits/master" target="_blank">The gitlab commit log</a>
*
***************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

/**
* @brief Constant Water Rate
*/
const int WATER_RATE = 5;
/**
* @brief Constant Sewer Rate.
*/
const int SEWER_RATE = 3;

/** ***************************************************************************
 * @author Amanda Lauen
 *
 * @par Description:
 *      This program will allow the user to calculate their total utilities
 *      bill using the Water Bill Estimation Tool. By entering in values for
 *      their previous bill, numbers of days late on payments, and previous 
 *      and current meter readings, the Water Bill Estimation tool will 
 *      calcuate the final utilities bill and the show how each factor 
 *      contributed to the total from the water and sewer consumption, 
 *      subtotals of both the water and sewer, and the late fees. The program
 *      ends with it saying good bye to the user and exiting once the user 
 *      hits any other key.
 *
 * @returns 0 program ran successful.
 *
 ***************************************************************************/
int main()
{
    string userName;   //contains the user's name inputted
    double prev_Bill;   //contains the previous bill inputted
    double num_Days_Late;   //contains the number of days late inputted
    int prev_meter_reading;   //contains the previous meter reading inputted
    int curr_meter_reading;   //contains the current meter reading inputted
    int water_consumption;   //contains the water consumption calculated
    int sewer_usage;   //contains the sewer usage calculated
    double water_consumption_price;   //contains the water consumption price
                                     // calculated
    double sewer_usage_price;   //contains the sewer usage price calculated
    double total_price;   //contains the total price calculated
    double late_fees;   //contains the late fees total calculated

    //Show opening statement and ask for user's name
    cout << "Welcome to Water Bill Estimation Tool!" << endl << endl;
    cout << "Please enter your name: ";
    cin >> userName;
    cout << "--------------------------------------------------" << endl;

    //Ask for previous bill
    cout << "Please enter value of previous water bill: ";
    cin >> prev_Bill;

    //Ask for numbers of days late
    cout << "Please enter number of days on late"  
         << " payment (0 for paid by due date): ";
    cin >> num_Days_Late;

    //Ask for previous meter rating
    cout << "Please enter previous meter reading (see past bill): ";
    cin >> prev_meter_reading;
    
    //Ask for current meter reading
    cout << "Please enter current meter reading: ";
    cin >> curr_meter_reading;
    cout << "--------------------------------------------------" << endl;
    
    // Calculate water and sewer consumption, subtotals of water and sewer, 
    // late fees, and total price
    water_consumption = curr_meter_reading - prev_meter_reading;
    water_consumption_price = WATER_RATE * water_consumption;
    sewer_usage = int(water_consumption * 1.2);
    sewer_usage_price = SEWER_RATE * sewer_usage;
    late_fees = (prev_Bill * pow(1.01, num_Days_Late)) - prev_Bill;
    total_price = water_consumption_price + sewer_usage_price + late_fees;


    // Show final menu with all the calculated values with setprecision of 2
    // and finish program with goodbye
    cout << fixed << setprecision(2);
    cout << "Your next water bill was estimated as follows: " << endl;
    cout << "Water consumption: " << water_consumption << endl;
    cout << "Water subtotal   : $" << water_consumption_price << endl;
    cout << "Sewer consumption: " << sewer_usage << endl;
    cout << "Sewer subtotal   : $" << sewer_usage_price << endl;
    cout << "Late fee         : $" << late_fees << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "TOTAL            : $" << total_price << endl;
    cout << "Good bye, " << userName << "!" << endl;
 
    return 0;
}
