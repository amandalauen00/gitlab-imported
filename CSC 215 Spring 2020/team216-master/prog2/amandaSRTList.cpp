/** ***************************************************************************
* @file
***************************************************************************/
#include "srtlist.h"
#include <iostream>
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function initilizes the count used in other functions in the SRT list
* functions.  This function also assigns head pointer to null pointer to
* help initilize this value to be changed in other functions.  This function
* has no return values because it is initilizing SRT List values.
*
***************************************************************************/
srtList::srtList()
{
    //Inililize count
    count = 0;
    //Initilize headpointer
    headptr = nullptr;

}
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function checks to see if the headpointer has any value inside of it
* that isn't nullpointer.  If so, then for each node in the SRT List, it will
* delete the node in order to clear the SRT list.  This function does not
* return anything because it is just a clearing list function.
*
***************************************************************************/
srtList::~srtList()
{
    //Initilize temporary value
    node *temp;
    //Check to see if there is anything in headpointer
    while (headptr != nullptr)
    {
        //For each node, delete it and keep going until list is clear
        temp = headptr;
        headptr = headptr->next;
        delete temp;
    }

}
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function prints out the information needed in the SRT file.  The
* function prints out the frame, start time, end time, and the caption.
* This is all printied in the correct SRT format. The information will then be
* outputted onto the screen.  This function does not return anything since
* it is merely copying into the new SRT format.
*
* @param[in,out]   fout - this is the ostream that the information will be
*                         copied into
*
***************************************************************************/
void srtList::printSRT(ostream &fout)
{
    //Print out the information in the SRT format
   //Initlize variables
    node *temp;
    temp = headptr;
    int frame = 1;
    //While the next node is not nullpointer, print out the information
    //in SRT format
    while (temp->next != nullptr)
    {
        cout << frame << endl;
        cout << temp->startTime << " --> " << temp->endTime << endl;
        cout << temp->caption << endl;
        cout << endl;
        //Update temp and frame
        temp = temp->next;
        frame = frame + 1;
    }


}

/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function etermines the size of the list.  The size is also indicated by
* the frames which are inclusive for how many frames are in the movie that the
* subtitles are being editied.  Since it is just showing the size, it returns
* the value in which it is under: count.
*
* @returns count when ran successful.
*
***************************************************************************/
int srtList::size()
{
    //Return the size of the SRT List
    return count;
}
/** ***************************************************************************
* @authors Amanda Lauen
*
* @par Description:
* This function validates that the string time that is passed in has the
* correct information in the SRT file.  The only acceptable values are
* characters 0 through 9 and three other spots for 2 colons and 1 comma.  This
* function returns true if the time string meets the criteria, or false when it
* doesn't.
*
* @param[in]   time - this variable indicates the time at which the caption is
*                     located
*
* @returns true or false when ran successful.
*
***************************************************************************/
bool srtList::validTime(string time)
{

    //Set variables
    int i;
    bool truthValue;

    //For each time slot, if it is not less than 10, then go into the loop
    for (i = 0; i < 10; i++)
    {
        if (i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7
            || i == 10 || i == 11 || i == 12)
        {
            //If the time characters equaled the criteria, then it is true
            //If not, then false
            if (time[i] == '0' || time[i] == '1' || time[i] == '2' ||
                time[i] == '3' || time[i] == '4' || time[i] == '5' ||
                time[i] == '6' || time[i] == '7' || time[i] == '8'
                || time[i] == '9')
            {
                truthValue = true;
            }
            else
            {
                truthValue = false;
            }
        }
        //If the time string was at locations 2 or 5, check to see if it's a 
        //colon or not
        if (i == 2 || i == 5)
        {
            if (time[i] = ':')
            {
                truthValue = true;
            }
            else
            {
                truthValue = false;
            }
        }
        //If the time string is at location 9, check to see if it is a comma
        //or not
        if (i == 9)
        {
            if (time[i] = ',')
            {
                truthValue = true;
            }
            else
            {
                truthValue = false;
            }

        }


    }
    //Return either true or false
    return truthValue;

}

