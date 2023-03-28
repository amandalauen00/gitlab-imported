/** **************************************************************************
 * @file
 ****************************************************************************/
#include "srtlist.h"
#include <string>
#include <list>


using namespace std;
/***************************************************************************//**
* @author Kiley Keck
*
* @par Description:
* This function will take in a valid frame number and copy the Starting time,
* ending time, and the caption into strings. if this is valid, it will return
* true.
*
* @param[in] frame
* @param[in] startingTime
* @param[in] endingTime
* @param[in] theCaption
* @returns true or false
*
******************************************************************************/
bool srtList::retrieve(int frame, string &startingTime,
    string &endingTime, string &theCaption)
{
    if (headptr == nullptr) //frame is invalid
    {
        return false;
    }

    //frame is valid
    else if (frame == 1)
    {
        startingTime = headptr->startTime;
        endingTime = headptr->endTime;
        theCaption = headptr->caption;
        return true;
    }
    else
    {
        node *temp = new(nothrow)node;
        temp = headptr->next;

        int i = 2;
        while (temp != nullptr)
        {

            if (frame == i)
            {
                startingTime = temp->startTime;
                endingTime = temp->endTime;
                theCaption = temp->caption;
                return true;
            }

            temp = temp->next;

            i++;
        }
        return false;
    }

}

/***************************************************************************//**
* @author Kiley Keck
*
* @par Description:
* This function will take in a frame number and a new caption. If the frame
* number is valid, a new caption will be copied to the frame and the
* function will return true. Otherwise the function will return false.
*
* @param[in] frame
* @param[in] theCaption
* @returns true or false
*
******************************************************************************/
bool srtList::update(int frame, string theCaption)
{
    if (headptr == nullptr) //frame is invalid
    {
        return false;
    }

    //frame is valid
    else if (frame == 1)
    {
        headptr->caption = theCaption;
        return true;
    }
    else
    {
        node *temp = new(nothrow)node;
        temp = headptr->next;

        int i = 2;
        while (temp != nullptr)
        {

            if (frame == i)
            {
                temp->caption = theCaption;
                return true;
            }

            temp = temp->next;

            i++;
        }
        return false;
    }

}



