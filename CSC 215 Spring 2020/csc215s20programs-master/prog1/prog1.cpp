/** **************************************************************************
 * @file 
 ****************************************************************************/
/** **************************************************************************
* @mainpage Program 1 - The Disgruntled Employee
*
* @section course_section Course Information
*
* @author Amanda Lauen
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
* @date Due March 1st, 2020
*
* @section program_section Program Information
*
* @details
* This program fixes the files that were corrupted by the disgruntled employee.
* The program starts by checking the command line to see if it has the correct 
* number.  If not, then an error message is outputted, and the program exits.  
* If so, then the program gets the current directory, and then it will check 
* to see if the current directory exists in memory or not.  If so, then the 
* directory will be outputted and will go into determining the directory 
* listing.  If not, then an error message is outputted, and the program exits.  
*
* The program then leads to the directory listing function, which determines 
* if the current directory is a subdirectory or not.  If not, then the program
* opens the file in the directory and determines if it is a BMP, GIF, JPG, or 
* a PNG file.  If it is not any of those files, the file is not renamed and 
* gets skipped over.  The file will check to see if it is any of the four 
* types of files each time.  To do this, it will seek to the beginning of the 
* file and read in from the precise number of bytes needed for each file type.  
*
* If the file has the first 2 bytes containing "BM," then the file is a BMP 
* file and will then get the width and height extracted from it.  To find the 
* width, the file will seek to the 18th integer (19th byte) in the file and 
* read in 4 bytes to see if the file contains a width.  The bytes in this file
* are reversed, so using a for loop, the width can be found by shifting left 8
* bytes and using the or symbol to do this for multiple files.  To find the 
* height, the file will seek to the 22nd integer (23rd byte) in the file and 
* read in 4 bytes to see if the file contains a width.  The bytes in this file
* are reversed, so using a for loop, the height can be found by shifting left 
* 8 bytes and using the or symbol to do this for multiple files.   After the 
* height and width are found, it will return to the directory listing function
* and will close the file in order to rename the file by attaching the height,
* width, and extension needed to identify the file as a BMP. If not, then the
* program will compare the file to the next type of file.
*
* If the file has the first 6 bytes containing "GIF89a" or "GIF87a", then the 
* file is a GIF file and will then get the width and height extracted from it.
* To find the width, the file will seek to the 6th integer (7th byte) in the 
* file and read in 2 bytes to see if the file contains a width.  The bytes in 
* this file are reversed, so using a for loop, the width can be found by 
* shifting left 8 bytes and using the or symbol to do this for multiple files.
* To find the height, the file will seek to the 8th integer (9th byte) in the 
* file and read in 2 bytes to see if the file contains a width.  The bytes in 
* this file are reversed, so using a for loop, the height can be found by 
* shifting left 8 bytes and using the or symbol to do this for multiple files.
* After the height and width are found, it will return to the directory listing
* function and will close the file in order to rename the file by attaching the
* height, width, and extension needed to identify the file as a GIF. If not, 
* then the program will compare the file to the next type of file.
*
* If the file has the first 8 bytes containing the coordinates (255,216) or 
* (255,217), then the file is a JPG file.  It will return to the directory 
* listing function and will close the file in order to rename the file by 
* attaching the extension needed to identify the file as a JPG.  If not, then 
* the program will compare the file to the next type of file. The width and 
* height are not needed for a JPG file.
*
* If the file has the first 8 bytes containing the bytes 137, 80, 78, 71, 13, 
* 10, 26, 10, '\0', then the file is a.PNG file and will then get the width 
* and height extracted from it.  To find the width, the file will seek to the 
* 16th integer (17th byte) in the file and read in 4 bytes to see if the file 
* contains a width.  The bytes in this file are not reversed, so using a for 
* loop, the width can be found by shifting left 8 bytes and using the or symbol
* to do this for multiple files.  To find the height, the file will seek to the
* 20th integer (21st byte) in the file and read in 4 bytes to see if the file 
* contains a width.  The bytes in this file are not reversed, so using a for 
* loop, the height can be found by shifting left 8 bytes and using the or 
* symbol to do this for multiple files.   After the height and width are found,
* it will return to the directory listing function and will close the file in 
* order to rename the file by attaching the height, width, and extension needed
* to identify the file as a PNG. If not, then the program will compare the file
* to the next type of file.
*
* After each file is renamed, then the program moves onto the next file until 
* all the files in the directory are renamed.  Once they are, then the program
* will go into the next directory and determine if there are files that need to
* be renamed or not.  If there are no more directories or all directory files 
* have been renamed, the program exits with return 0 when ran successfully.
*
* @section compiling_section Compiling and Usage
*
* @par Compling Instructions:
*      none - a straight compile and link with no external libraries.
*
* @par Usage:
  @verbatim
  c:\> prog1.exe ../../directory/../directory2/../../directory(n)
       directory   -   Holds the name of the current directory and will keep
                       reading each directory until the nth directory
  d:\> c:\bin\prog1.exe
  @endverbatim
*
* @par Modifications and Development Timeline:
* <a target="_blank" 
* href=https://gitlab.mcs.sdsmt.edu/7452203/csc215s20programs/-/commits/master
* ">click here </a>
*
***************************************************************************/
#include "imageClassifier.h"
#include "imageDimensions.h"
#include "utilities.h"

using namespace std;
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function is the main function that starts the whole program off.  
* First, it checks the command line arguments and sees if there are less than 
* two.  If so, then an error message is outputted.  The next thing it does is 
* get the current directory.  It will then check if the current directory exist
* , output it, and continue on getting a new directory.  If the directory 
* doesn't exist, then an error message will be outputted.  This program exists 
* with 0 to indicate that it ran successfully.
*
* @param[in]   argc - a count of the command line arguments used to start
*                       the program.
* @param[in]   argv - a 2D character array of each argument.  Each token
*                       occupies one line in the array.
*
* @returns 0 program ran successful.
*
***************************************************************************/
int main ( int argc, char **argv )
{
    //Initilize variables
    ifstream fin;
    char buffer1[_MAX_PATH];
    
    //Check for correct number of command line arguments
    if ( argc < 2 )
    {
        cout << "Usage prog1.exe <directory> <filename>";
        return 0;
    }
    
    //Get the current directory
    _getcwd ( buffer1, _MAX_PATH );

    //Check that the specified directory exists and change to that directory
    for ( int i = 1; i < argc; i++ )
    {
        //If the specific directory exists, output it and go into a 
        //new directory listing
        if ( _chdir ( argv[i] ) == 0 )
        {
            cout << "Current Working Directory is: " << argv[i] << endl;
            dirlisting();
            cout << endl;
            _chdir ( buffer1 );
        }
        //If not, then output an error
        else
        {
            cout << "Unable to process directory " << buffer1 << endl;
        }
    }
    
   
    return 0;
}