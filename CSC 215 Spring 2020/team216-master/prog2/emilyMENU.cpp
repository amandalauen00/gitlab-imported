/** ***************************************************************************
* @file
***************************************************************************/
#include "menu.h"
#include <string>
#include <iostream>
#include <vector>

using std::string;
using namespace std;

/** ***************************************************************************
* @authors Emily Nix
*
* @par Description:
* This function will ensure the position the user is trying to insert into
* exists. Then it will increase the size of the menu so there is room for
* the inserted menu item. Next the function will shift all of the existing
* menu items to make sure there is an empty space in the correct location for
* the new item. Then it will insert the new item into the empty space.
* The function will return true if it is sucessful.
*
*
* @param[in]   item
* @param[in]   pos
*
* @returns false function was not successful.
* @returns true function ran successfully.
*
***************************************************************************/

bool menu::addMenuItem(string item, int pos)
{
    int i;
    //find the size of the menu
    int size = (int)theMenu.size();

    //make sure position exists
    if (pos < 0 || pos > size)
    {
        return false;
    }

    //make room for the new menu item
    theMenu.resize(size + 1);
    //find the position to insert the menu item
    for (i = size; i > pos; i--)
    {
        //theMenu.insert(i + 1, theMenu.at(i));
        theMenu[i] = theMenu[i - 1]; //using random access??
    }

    theMenu[pos] = item; //using random access

    return true;
}

/** ***************************************************************************
* @authors Emily Nix
*
* @par Description:
* This function will ensure the position the user is trying to delete
* exists. Then it will find the item the user would like to delete and
* erases it.
*
*
* @param[in]   pos
*
* @returns false function was not successful.
* @returns true function ran successfully.
*
***************************************************************************/
bool menu::removeMenuItem(int pos)
{
    size_t size = theMenu.size();

    //make sure position exists
    if (pos < 0 || pos > size)
    {
        return false;
    }

    //erase the item
    theMenu.erase(theMenu.begin() + (pos - 1));


    return true;
}

/** ***************************************************************************
* @authors Emily Nix
*
* @par Description:
* This function will find the size of the current menu. Then it will output
* each menu item one by one in the correct format.
*
*
***************************************************************************/
void menu::printMenu()
{
    unsigned int i;
    size_t size = theMenu.size();

    //output each menu item formatted correctly
    for (i = 0; i < size; i++)
    {
        cout << (1 + i) << ") " << theMenu.at(i) << endl;
    }
}
