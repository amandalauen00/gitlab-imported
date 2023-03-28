/** **************************************************************************
 * @file
 ****************************************************************************/
 /** **************************************************************************
 * @mainpage Program 2 - The SRT Editor
 *
 * @section course_section Course Information
 *
 * @authors Amanda Lauen, Emily Nix, Kiley Keck
 *
 * @par Professor:
 *      Roger Schrader
 *
 * @par Course:
 *      CSC215 - M002 - Programming Techniques
 *
 * @par Location:
 *      Classroom Building - Room 118
 *
 * @date Due April 3rd, 2020
 *
 * @section program_section Program Information
 *
 * @details
 * This program will allow a user to edit srt files and add or remove frames
 * within the file. It starts by taking a command line argument and if the file
 * name exists, the program will insert all of the frames from the file into
 * our list. If the file doesn't exist, then the program just procedes to the
 * main menu.
 *
 * The main menu gives 7 options for the user to choose from. Those options are
 * add a subtitle frame, remove a frame, retrieve a frame, update a frame,
 * print subtitles to screen, print range of subtitles, or exit.
 * Each option will lead to a function in the program that will help do those
 * things for the user, and the functions are described later in the program.
 * If the user chooses to exit, a submenu will appear prompting the user with
 * two options, one, save to the file and exit, or two, exit without saving.
 *
 * Two classes are used in this program, the menu class, and the srtList class.
 * These classes store our functions used to add, remove, retrieve a frame etc.
 *
 * @section compiling_section Compiling and Usage
 *
 * @par Compling Instructions:
 *      none - a straight compile and link with no external libraries.
 *
 * @par Usage:
   @verbatim
   c:\> prog2.exe inputFile
                  inputFile - Holds the file that needs to be input.
   @endverbatim
 *
 * @todo Insert and Update functions do not take in multiple lines
 * @todo Missing 3 error statements
 *
 * @par Modifications and Development Timeline:
 * <a target="_blank"
 * href="https://gitlab.mcs.sdsmt.edu/csc215s20/team216/-/commits/master">click here </a>
 *
 ***************************************************************************/
#include "menu.h"
#include "srtlist.h"

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include <list>

using namespace std;
/** ***************************************************************************
* @authors Amanda Lauen, Emily Nix, and Kiley Keck
*
* @par Description: This function declares all of the variables necessary.
*                   It will ensure the correct number of command line
*                   arguments and will output an error message if there is not.
*                   It opens the file and ensures it will open.
*                   Then the function checks to see if it exists and then sets
*                   up the main menu.  The menu takes in the user input and
*                   directs it to the function it needs error checking on the
*                   way. The program then closes the file and ends with
*                   return 0 when ran successully.
*
* @param[in]   argc - a count of the command line arguments used to start
*                       the program.
* @param[in]   argv - a 2D character array of each argument.  Each token
*                       occupies one line in the array.
*
* @returns 0 program ran successful.
*
***************************************************************************/
int main(int argc, char **argv)
{
    //Initilize variables
    menu mainMenu;
    srtList list;
    ifstream fin;
    ofstream fout;
    string inputFile;
    string startingTime;
    string endingTime;
    string theCaption;
    string theCaptionTwo = "";
    bool wMenu = true;
    // char frameTwo[100];
    // char tempTwo[100];
    //char frameInfo[1000];
    string temp;
    int userNum = 0;
    int submenuSelection = 0;
    int frame = 0;
    int i = 0;
    int j = 0;
    int frame1;
    int frame2;

    //Check the command line arguments
    if (argc < 2 || argc > 2)
    {
        cout << "Incorrect number of command lines, exiting program";
        cout << endl;
        cout << "Usage: prog2.exe <srtFile>";
        return 0;
    }

    //Assign the input value to the first value in the argv array
    inputFile = argv[1];

    //Open the file
    fin.open(inputFile);

    //Check to see if the file is open
    if (!fin.is_open())
    {
        cout << "Unable to open file: " << argv[1];
        return 0;
    }

    //If the file exists
    if (fin)
    {
        while (!fin.eof())
        {
            theCaption.clear();

            //fin.getline(frameInfo, 1000000, '\n\n');
            //while (j != '\0')
            //{
            //    theCaption += frameInfo[j];
            //    j++;
            //}
            //cout << theCaption;

            fin >> frame;
            fin.ignore();
            // turn into int
            //frame = atoi(frameTwo);

            getline(fin, startingTime, '-');
            fin.ignore(2);
            getline(fin, endingTime, '\n');

            getline(fin, theCaptionTwo, '\n');

            while (theCaptionTwo != "")
            {
                theCaption += theCaptionTwo + '\n';
                theCaptionTwo.clear();
                getline(fin, theCaptionTwo, '\n');

            }

            list.insert(startingTime, endingTime,
                theCaption); //Insert all the frames within the file into your list

        }
    }

    setUpMainMenu(mainMenu); //Proceed to main menu function

    //Menu is presented
    while (userNum != 7)
    {
        mainMenu.printMenu();
        cout << "Select a menu option: ";
        cin >> userNum;
        cout << endl;
        //If the user enters 1
        if (userNum == 1)
        {
            //Prompt for start time, end time, and caption
            cout << "Starting time: ";
            cin >> startingTime;

            if (startingTime == "0")
            {
                cout << "Starting time is not in a valid format" << endl;

            }

            cout << "Ending time: ";
            cin >> endingTime;

            if (endingTime == "0")
            {
                cout << "Ending time is not in a valid format" << endl;
            }

            /*
            else if ( startingTime < endingTime )
        {
        cout << "Starting time must come after the ending time of the "
             << "previous frame if it exists" << endl;
            */


            cout << "Caption: ";
            cin >> theCaption;

            /*while(theCaption != "\n")
            {
                cout << "The Caption Two: ";
                cin >> theCaption;
                theCaption += theCaption + '\n';
            }
            */
            /*while(theCaption != "\n")
            {
                cin >> theCaption;
                cout << theCaption;

            }
            */
            //If caption is not blank, insert it
            if (theCaption != "")
            {
                list.insert(startingTime, endingTime, theCaption);
                //Error Statement: Unable to insert the frame into the SRT list
            }
            else
            {
                cout << "The caption is empty" << endl;
            }
        }
        //If the user enters 2
        else if (userNum == 2)
        {
            //Prompt for frame number
            cout << "Frame Number: ";
            cin >> frame;
            //If the frame is within the range, remove it
            if (frame != 0 && frame < list.size())
            {
                list.remove(frame);
            }
            else
            {
                cout << "Unable to remove frame # from the SRT list" << endl;
            }
        }
        //If the user enters 3
        else if (userNum == 3)
        {
            //Prompt for the frame
            cout << "Frame: ";
            cin >> frame;
            //If the frame is within the range, retrieve the info
            if (frame != 0 && frame < list.size())
            {
                list.retrieve(frame, startingTime, endingTime, theCaption);
                cout << frame << endl;
                cout << startingTime << endl;
                cout << endingTime << endl;
                cout << theCaption << endl;
            }
            else
            {
                cout << "Unable to retrieve frame # from the SRT list" << endl;
            }
        }
        //If the user enters 4
        else if (userNum == 4)
        {
            //Prompt for the frame
            cout << "Frame: ";
            cin >> frame;
            //If the file is within the range, retrieve it and rewrite it
            if (frame != 0 && frame < list.size())
            {
                list.retrieve(frame, startingTime, endingTime, theCaption);
                cout << frame << endl;
                cout << startingTime << " --> " << endingTime << endl;
                cout << theCaption << endl;

                cout << "New Caption: ";
                cin >> theCaption;
                list.update(frame, theCaption);
                cout << endl;
            }
            else
            {
                cout << "Unable to update frame # from the SRT list to be "
                    << "updated" << endl;

            }
        }
        //If the user enters 5
        else if (userNum == 5)
        {
            //print Subtitles to the screen
            list.printSRT(fout);
        }
        else if (userNum == 6)
        {
            //Prompt for the first and last frames
            cout << "First frame: ";
            cin >> frame1;
            cout << "Last frame: ";
            cin >> frame2;
            for (i = frame1; i < frame2; i++)
            {
                //If the frames are within the ranges, retrieve the caption
                if (i >= 0 && i < list.size())
                {
                    list.retrieve(i, startingTime, endingTime, theCaption);
                    cout << theCaption;
                    cout << endl;
                }
                else
                {
                    cout << "Unable to print frame # from the SRT list" << endl;
                }

            }


        }
        //If the user enters 7
        else if (userNum == 7)
        {
            //Set up submenu
            submenuSelection = mainMenu.getmenuSelection(wMenu);
            //If the user enters 1
            if (submenuSelection == 1)
            {
                //Save file and exit
                fout.open(argv[1]);
                list.printSRT(fout); //identifier not found
                fout.close();
                return 0;
            }
            //If the user enters 2
            else if (submenuSelection == 2)
            {
                //Exit without saving
                return 0;
            }

            return 0;
        }
        //If an invalid user entry is entered
        else
        {
            cout << "Invalid option" << endl; //error message and reprint menu
            mainMenu.printMenu();
            cout << "Select a menu option: ";
            cin >> userNum;
            cout << endl;
        }
    }
    //Close file
    fin.close();
    return 0;
}