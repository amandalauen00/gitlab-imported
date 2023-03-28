/** ***************************************************************************
* @file
***************************************************************************/
#ifndef __SRTLIST_H_
#define __SRTLIST_H_

#include <string>
#include <ostream>
#include <iostream>
#include <list>

using namespace std;
/** ***************************************************************************
* @authors Amanda Lauen, Emily Nix, and Kiley Keck
*
* @par Description:
*      This is the SRT list class.  It defines all the functions used in the
*      program.
*
***************************************************************************/
class srtList
{
public:
    srtList();
    ~srtList();
    bool insert(string startingTime, string endingTime,
        string theCaption);
    bool remove(int frame);
    bool retrieve(int frame, string &startingTime,
        string &endingTime, string &theCaption);
    bool update(int frame, string theCaption);
    void printSRT(ostream &fout);
    int size();
private:
    bool validTime(string time);
    /**
   * @brief Holds data regarding the information from the movie transcript
   */
    struct node
    {
        string startTime;  /**< Holds the start time.  */
        string endTime;   /**< Holds the end time.  */
        string caption;   /**< Holds the caption.  */
        node *next;       /**< Holds the next node in the list.  */
    };
    int count;        /**< Holds the count.  */
    node *headptr;    /**< Holds the headpointer.  */



};
#endif
