/** ***************************************************************************
* @file
***************************************************************************/
#include "menu.h"
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using namespace std;

/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function initilizes an empty vector and intiilized theMenu to be empty
* as well.  This function is used in other menu functions when changing theMenu
* or the vector of strings.  This function does not return anything since
* it is just an initilization function.
*
***************************************************************************/
menu::menu()
{
    //Initilize variables for other functions
    vector <string> empty = {};
    theMenu = empty;
}
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function brings in the menuList to be changed.  The menuList can be
* changed by setting theMenu to the menu list.  The reason for this is so that
* the menu can appear even when a list of menu's is passed in.  This function
* doesn't return anything since it's another initilization function.
*
* @param[in, out]   menuList - This variable holds the list of the menu being
*                              passed in
*
***************************************************************************/
menu::menu(vector <string> &menuList)
{
    //Set theMenu to the menuList
    theMenu = menuList;
}
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function serves the purpose of creating a menu when a menu is passed in.
* This function takes the menu that is being passed in and makes it equal to the
* menu that the program uses.  This program doesn't return anything because it
* is just an initilization function.
*
* @param[in, out]   aMenu - this value holds a seperate menu that is able to be
*                           brought in to make a new menu
*
***************************************************************************/
menu::menu(menu &aMenu)
{
    //Set theMenu to theMenu under aMenu
    theMenu = aMenu.theMenu;
}

/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This funcion gets the menu selection from the user in the secondary menu.
* The function first sees if the withMenu value is true or false.  If so then
* the program sets up the secondary menu and asks the user for what option
* they want to do with the file in which they edited.  If the user picks option
* 1 or if they pick option 2, then the program returns the value to prog2.cpp.
* If the number is not 1 or 2, then an error message will be outputted and will
* reprompt the user for another value until 1 or 2 is entered. If withMenu is
* false, then the menu is not generated and just returns out of function and
* program. The function returns the submenuSelection when ran succesfully.
*
* @param[in]   withMenu  - this varaible holds the menu that is being
*                          used and is set to true so that the secondary
*                          menu can be set up and ran
*
* @returns submenuSelection function ran successful.
*
***************************************************************************/
int menu::getmenuSelection(bool withMenu)
{
    //Initilize the vector for the menu;
    vector<string> v = { "  1) Save to file and exit",
                         "  2) Exit without saving"
    };
    //Initlizlize the selection from user
    int submenuSelection = 0;

    //If the withMenu is false, exit the program
    if (withMenu == false)
    {
        return -1;
    }
    //If the menu is true, execute asking the user for what value they want for
    //their selection
    else
    {
        while (submenuSelection != 1 && submenuSelection != 2)
        {
            //Prompt user with menu and a place for them to enter their choice
            subMenu(v);
            cout << "Enter choice: ";
            cin >> submenuSelection;
            cout << endl;
            //If it's one or two, then it wil return 1 or 2
            if (submenuSelection == 1)
            {
                return submenuSelection;
            }
            else if (submenuSelection == 2)
            {
                return submenuSelection;
            }
            //If it isn't one or two, output the error message and prompt
            //user again
            else
            {
                cout << "Invalid option." << endl << endl;
            }
        }
    }
    //Return the value the user put in
    return submenuSelection;
}
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function gets the size of the menu.  This value is then returned and
* displayed where it needs to be.
*
* @return theMenu.size() when ran successfully.
*
***************************************************************************/
int menu::size()
{
    //Return the menu size
    return (int)theMenu.size();
}
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function clears the menu of any values entered in by the user.
* This function doesn't return anything since it is a clearing function.
*
***************************************************************************/
void menu::clear()
{

    //Clear the menu
    theMenu.clear();

}