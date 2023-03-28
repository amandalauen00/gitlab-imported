/** **************************************************************************
 * @file
 ****************************************************************************/
#include "menu.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

/***************************************************************************//**
* @author Kiley Keck
*
* @par Description:
* This function will update a menu location with a new phrase. If this is done
* successfully, then the function will return true. Otherwise, it will return
* false.
*
* @param[in] item
* @param[in] pos
* @returns true or false
*
******************************************************************************/
bool menu::updateMenuItem(string item, int pos)
{
    //Find the position
    theMenu.at(pos - 1) = item;
    //If the position is the same as the item, return true
    if (theMenu.at(pos - 1) == item)
    {
        return true;
    }
    //If not, return false
    else
    {
        return false;
    }
}

/***************************************************************************//**
* @author Kiley Keck
*
* @par Description:
* This function will set up the main menu and it's options.
*
* @param[in] ourMenu
* @returns none
*
******************************************************************************/
void setUpMainMenu(menu &ourMenu)
{
    //Set up main menu options for the user
    unsigned int i;
    vector<string> v = { "Add a Subtitle Frame", "Remove a frame",
                        "Retrieve a frame", "Update a frame",
                        "Print subtitles to screen",
                        "Print range of subtitles", "Exit"
    };
    for (i = 0; i < v.size(); i++)
    {
        ourMenu.addMenuItem(v.at(i), ourMenu.size());
    }
}

/***************************************************************************//**
* @author Kiley Keck
*
* @par Description:
* This function will set up the submenu and it's options.
*
* @param[in] v
* @returns none
*
******************************************************************************/
void subMenu(vector<string> v)
{
    //Sets up submenu for the user
    unsigned int i;
    for (i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }

}