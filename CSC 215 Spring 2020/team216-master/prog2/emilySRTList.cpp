/** ***************************************************************************
* @file
***************************************************************************/
#include "srtlist.h"

/** ***************************************************************************
* @authors Emily Nix
*
* @par Description:
* This function will add a frame into any part of the linked list regardless
* of it being added to the front, middle, or end of the list. It will keep
* track of how many items are in the list and will also error check. The
* function will also be able to add to an empty list.
*
*
* @param[in]   startingTime
* @param[in]   endingTime
* @param[in]   theCaption
*
* @returns false function was not successful.
* @returns true function ran successfully.
*
***************************************************************************/
bool srtList::insert(string startingTime, string endingTime,
    string theCaption)
{
    //create nodes to keep track of where the function is at in the list
    node *temp = nullptr;
    node *curr = nullptr;
    node *prev = nullptr;

    temp = new (nothrow) node;

    //make sure there is a place to put the frame into or output an error
    if (temp == nullptr)
    {
        cout << "Unable to allocate memory." << endl;
        return false;
    }

    //allow the funciton to access each individual part of the array
    temp->caption = theCaption;
    temp->startTime = startingTime;
    temp->endTime = endingTime;
    temp->next = nullptr;

    //This allows the function to add to an empty list
    if (headptr == nullptr)
    {
        headptr = temp;
        count++;
        return true;
    }

    /*if the new node comes before the first one on the list it is inserted
    and becomes the new first node*/
    if (temp->endTime > headptr->startTime)
    {
        temp->next = headptr;
        headptr = temp;
        count++;
        return true;
    }

    //put current and previoius to the first node
    prev = headptr;
    curr = headptr;

    /*if the new node goes in the middle of the list it will move the pointers
    down until the new node does not come after the next node*/
    while (curr != nullptr && temp->endTime < curr->startTime)
    {
        prev = curr;
        curr = curr->next;
    }



    /*if the node is being inserted at the end of the list put it after the
    last node*/
    if (curr == nullptr)
    {
        prev->next = temp;
        temp->next = curr;
        count++;
        return true;
    }

    return true;
}

/** ***************************************************************************
* @authors Emily Nix
*
* @par Description:
*
* This funciton will remove a frame. This function will ensure there is a
* frame to be removed and then will successfully remove it from anywhere in
* the list, whethter it is in the front, middle, end, or the last frame left.
* This function will also keep track of the number of frames that are in the
* linked list so more than one fram can be removed.
*
* @param[in]   frame
*
* @returns false if the list is already empty
* @returns false if the list is already empty
* @returns true the frame was removed successfully.
* @returns true function ran successfully.
*
***************************************************************************/
bool srtList::remove(int frame)
{
    //create nodes to keep track of where the program is at in the list
    node *temp = nullptr;
    node *curr = nullptr;
    node *prev = nullptr;
    int num = 1;

    //check if there are no frames to remove and then exit if there aren't
    if (headptr == nullptr)
    {
        return false;
    }

    /*if the user is removing the first item it reassigns the headptr so it
    skips over the first frame, removing that frame from the list*/
    if (num == frame)
    {
        temp = headptr;
        headptr = headptr->next;
        delete temp;
        count--;
        return true;
    }

    //reassign revious and current pointers to the begining of the list
    prev = headptr;
    curr = headptr;

    /*if the user is removing an item from the middle of a list it will
    it will reasign the previous frame with the location of the next frame
    removing the particular frame from the list*/
    while (curr != nullptr && num != frame)

    {
        prev = curr;
        curr = curr->next;
        num++;
    }

    //if the program was already at the last frame exit by returning false
    if (curr == nullptr)
    {
        return false;
    }


    prev->next = curr->next;
    delete curr;
    num--;
    return true;
}
