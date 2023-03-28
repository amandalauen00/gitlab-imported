/** ***************************************************************************
* @file
***************************************************************************/
#ifndef __MENU_H_
#define __MENU_H_

#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
*      This is the Menu list class.  It defines all the functions used in the
*      program.
*
***************************************************************************/
class menu
{
    public:
        menu();
        menu ( vector <string> &menuList );
        menu ( menu &aMenu );
        
        bool addMenuItem ( string item, int pos );
        bool removeMenuItem ( int pos );
        bool updateMenuItem ( string item, int pos );
        
        void printMenu();
        int getmenuSelection ( bool withMenu = true );
        int size();
        void clear();
        
    private:
        
        vector <string> theMenu; /**< Holds the menu used in the program  */ 
        
};
#endif