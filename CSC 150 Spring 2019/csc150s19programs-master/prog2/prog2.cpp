/** ***************************************************************************
* @file
*
* @mainpage Program 1 - Drive Through
*
* @section course_section Course Information
*
* @author Amanda Lauen
*
* @date February 19, 2019
*
* @par Professor
*      Daniel De Castro
*
* @par Course
*      CSC150 - M002 - 12:00pm
*
* @par Location
       McLaury - Room 205
*
* @section program_section Program Information
* This program will take a order from a costumer and calculate the total 
* bill. After presenting the main menu, it will ask for a 
* selection.  The only valid options are 1, 2, 3, 4, and 0.  If 
* another number is entered, it will output an error message, and then 
* present the main menu again.  The program will repeat this until 
* the user to enters a valid number. If option 1 is selected, the 
* New Order menu option, it will start a new order, resetting 
* all current variables to zero. 
*
* If option 2 is selected, the program will output a submenu showing all beverage 
* items under the name of Add Item.  The Add Item submenu will output the 
* following menu of options to the screen. After presenting this submenu, 
* it will ask for a selection between coffee, tea, or juice.  The only valid 
* options are 1, 2, 3, and 0. If another number is entered, it will 
* output an error message, and present the submenu again.  The program will 
* repeat this function until the user inputs a valid option.  For options 1 
* through 3, it will ask for the number of items to be added to the order, 
* and then it will calculate and show the complete subtotal, and then it 
* will present this submenu again and allow user to enter another 
* selection. If 0 is selected, it will return to the main menu.  
*
* If option 3 is selected, the Remove submenu to change 
* an item will appear. The change order submenu will output the summary and then 
* the following menu of options to the screen. After presenting this submenu, it will ask 
* for a new selection.  The only valid options are 1, 2, 3, and 0. If another number is entered, 
* it will output an error message, and present the submenu once again.  The program will 
* repeat this until the user inputs a valid option.  If 0 is selected, 
* it will return to the main menu. For options 1 through 3, it will ask for 
* the number of items to be removed to the order.  The user will need to check if that is a valid 
* entry.  Then, if the item is still in the order, it will calculate and show the complete subtotal, and then 
* it will present the submenu again and allow user to enter another selection. 
*
* If option 4 is selected, the program will show the order summary and 
* allow for confirmation on the order. The finalize order menu outputs the order summary 
* and then the following menu of confirm or revoke the orders to the screen. The program will 
* only display an item if there is one or more of that item being purchased. After presenting 
* this submenu, it will ask for a selection. The only valid options are 1 and 2. If another number 
* is entered, it will output an error message, present the menu and allow the user 
* to enter another number.   If 2 is selected, it will return to the main menu.  If 1 is 
* selected, it will display a message, Thank you for your purchase!, start a new order, and return to the main menu.  
*
* The option 0 is the only way to exit from this program. 
*
* @section compiling_section Compiling and Usage
*
* @verbatim
  c:\> prog2.exe    
  d:\> c:\bin\prog2.exe    
  @endverbatim 
*
* @section todo_bugs_modifications_section Todo, Bugs, and Modifications
*
* @bug Rounding error when it comes to total bill
*
* @todo None
*
***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/**
* @brief Number of spaces shortcut.
*/
const string SPACES = "    ";
/**
* @brief Constant coffee price.
*/
const double COFFEE_PRICE = 1.00;
/**
* @brief Constant tea price.
*/
const double TEA_PRICE = 0.75;
/**
* @brief Constant juice price.
*/
const double JUICE_PRICE = 1.00;
/**
* @brief Sales tax added to the total price.
*/
const double SALES_TAX = .05;
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description:
*       This program will allow someone to order a cup and/or cups of coffee, tea, or juice from the new SDSM&T Drive Through Coffee Shop.
*       By entering in certian positive constant numbers, the user will be able to access several submenus allowing them to add/remove items and finalize their order.
*       If any other number is entered, an error message will apprear and redirect the user back to the main menu or submenu it is entered at.
*       The program will keep executing until 0 is entered at the end.
*
* @returns 0 program ran successful.
*
***************************************************************************/
int main()
{
    int choice_item = 1;
    int choice_number = 1;
    double coffee_subtotal = 0;
    double complete_subtotal = 0;
    double complete_tax = 0;
    double complete_total = 0;
    int confirm_number = 0;
    double juice_subtotal = 0;
    int num_coffee = 0;
    int num_juice = 0;
    int num_tea = 0;
    double tea_subtotal = 0;
    int total_num_coffee = 0;
    int total_num_juice = 0;
    int total_num_tea = 0;
   
    while (choice_number != 0)
    {
        choice_item = 1;
        cout << "SDSM&T Coffee Shop Drive Through" << endl;
        cout << "==================================================" << endl;
        cout << "1) New order / Cancel current order" << endl;
        cout << "2) Add item" << endl;
        cout << "3) Remove item" << endl;
        cout << "4) Finalize order" << endl;
        cout << "0) Exit program" << endl << endl;
        cout << fixed << setprecision(2);

        cout << "Enter your choice: ";
        cin >> choice_number;
        if (choice_number == 1)
        {
            cout << endl;
            total_num_coffee = 0;
            total_num_tea = 0;
            total_num_juice = 0;
            complete_subtotal = 0;
        }
        else if (choice_number == 2)
        {
            while (choice_item != 0)
            {
                cout << endl << "    " << "SDSM&T Coffee Shop - Add Item" << endl;
                cout << "    ==================================================" << endl;
                cout << "    1) Coffee " << endl;
                cout << "    2) Tea " << endl;
                cout << "    3) Juice " << endl;
                cout << "    0) Return to main menu " << endl << endl;
                cout << "    Select item to add, or 0 to finish: ";
                cin >> choice_item;
                if (choice_item == 1)
                {
                    cout << endl << "        How many cups of coffee? ";
                    cin >> num_coffee;
                    total_num_coffee += num_coffee;
                    coffee_subtotal = total_num_coffee * COFFEE_PRICE;
                    complete_subtotal = coffee_subtotal + tea_subtotal + juice_subtotal;
                    cout << "        " << num_coffee << " cups of coffee added to the order.  Subtotal: $" << complete_subtotal << endl;
                }
                else if (choice_item == 2)
                {
                    cout << "        How many cups of tea? ";
                    cin >> num_tea;
                    total_num_tea += num_tea;
                    tea_subtotal = total_num_tea * TEA_PRICE;
                    complete_subtotal = coffee_subtotal + tea_subtotal + juice_subtotal;
                    cout << "        " << num_tea << " cups of tea added to the order. Subtotal: $" << complete_subtotal << endl;
                }
                else if (choice_item == 3)
                {
                    cout << "        How many cups of juice? ";
                    cin >> num_juice;
                    total_num_juice += num_juice;
                    juice_subtotal = total_num_juice * JUICE_PRICE;
                    complete_subtotal = coffee_subtotal + tea_subtotal + juice_subtotal;
                    
                    cout << "        " << num_juice << " cups of juice added to the order. Subtotal: $" << complete_subtotal << endl;
                }
                else if (choice_item == 0)
                {
                    cout << endl;
                }
                else
                {
                    cout << endl << "        This is not a valid number, Try again." << endl;
                }
            }

        }
        else if (choice_number == 3)
        {
            while (choice_item != 0)
            {
                cout << endl << "    SDSM&T Coffee Shop - Change Order" << endl;
                cout << "    ==================================================" << endl;
                cout << "    Order Summary" << endl;
                cout << "    Item" << "        Quantity     " << "       Cost      " << endl;
                cout << "    -------------------------------------------------- " << endl;
                if (total_num_coffee != 0)
                {
                    cout << "    Coffee         " << total_num_coffee << SPACES << SPACES << SPACES << SPACES << coffee_subtotal << endl;
                }
                if (total_num_tea != 0)
                {
                    cout << "    Tea            " << total_num_tea << SPACES << SPACES << SPACES << SPACES << tea_subtotal << endl;
                }
                if (total_num_juice != 0)
                {
                    cout << "    Juice          " << total_num_juice << SPACES << SPACES << SPACES << SPACES << juice_subtotal << endl << endl;
                }
                cout << endl << "    Subtotal                        " << complete_subtotal << endl << endl;
                cout << "    1) Coffee " << endl;
                cout << "    2) Tea " << endl;
                cout << "    3) Juice " << endl;
                cout << "    0) Return to main menu " << endl << endl;
                cout << "    Select item to remove, or 0 to finish: ";
                cin >> choice_item;
                if (choice_item == 1)
                {
                    complete_subtotal -= coffee_subtotal;
                    total_num_coffee = 0;
                    coffee_subtotal = 0;
                }
                else if (choice_item == 2)
                {
                    complete_subtotal -= tea_subtotal;
                    total_num_tea = 0;
                    tea_subtotal = 0;
                }
                else if (choice_item == 3)
                {
                    complete_subtotal -= juice_subtotal;
                    total_num_juice = 0;
                    juice_subtotal = 0;
                }
                else if (choice_item == 0)
                {
                    cout << endl;
                }
                else
                {
                    cout << endl << "        This is not a valid number, Try again." << endl;
                }
            }
        }
        else if (choice_number == 4)
        {
            while (choice_item != 0)
            {
                complete_tax = complete_subtotal * SALES_TAX;
                complete_total = complete_subtotal + complete_tax;
                confirm_number = 1;
                cout << endl << "SDSM&T Coffee Shop - Finalize Order" << endl;
                cout << "==================================================" << endl;
                cout << "Order Summary" << endl;
                cout << "Item  " << "          Quantity      " << "      Cost         " << endl;
                cout << "--------------------------------------------------" << endl;
                if (total_num_coffee != 0)
                {
                    cout << "    Coffee          " << total_num_coffee << SPACES << SPACES << SPACES << SPACES << coffee_subtotal << endl;
                }
                if (total_num_tea != 0)
                {
                    cout << "    Tea             " << total_num_tea << SPACES << SPACES << SPACES << SPACES << tea_subtotal << endl;
                }
                if (total_num_juice != 0)
                {
                    cout << "    Juice           " << total_num_juice << SPACES << SPACES << SPACES << SPACES << juice_subtotal << endl << endl;
                }
                cout << endl << "    Subtotal                         " << complete_subtotal << endl;
                cout << "    Taxes (5%)                       " << complete_tax << endl;
                cout << "    Total                            " << complete_total << endl << endl;
                cout << endl << "    Confirm order?" << endl;
                cout << "    1) Yes " << endl;
                cout << "    2) No (Return to main menu) " << endl;
                cout << SPACES;
                cin >> confirm_number;
                if (confirm_number == 1)
                {
                    cout << SPACES;
                    cout << "Thank you for your purchase!" << endl << endl;
                    choice_item = 0;
                    total_num_coffee = 0;
                    total_num_tea = 0;
                    total_num_juice = 0;
                    complete_subtotal = 0;
                    coffee_subtotal = 0;
                    tea_subtotal = 0;
                    juice_subtotal = 0;
                }
                else if (confirm_number == 2)
                {
                    cout << endl;
                    choice_item = 0;

                }
                else
                {
                    cout << SPACES;
                    cout << "This is not a valid number, Try again." << endl;
                }
            }
        }
        else if (choice_number == 0)
        {
            choice_number = 0;
        }
        else
        {
            cout << SPACES;
            cout << "This is not a valid number, Try again." << endl;
        }
    }
    return 0;
}