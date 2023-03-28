/** ***************************************************************************
* @file
***************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "utilities.h"
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function gets the directory listing of the file. This function gets 
* the current directory listing and determines if the file is not in a sub 
* directory or not. If it isn't then it will go ahead and start determining if 
* the file is a BMP,JPG,GIF,or PNG file.  If it is, then it will do the 
* conversions to get width, height, and rename the files.  If it is a sub 
* directory, it will be skipped and not be named.  This file does not return 
* anything if it is successful.
*
***************************************************************************/
void dirlisting()
{
    //Declare variables
    _finddata_t aFile;
    intptr_t dHandle;
    ifstream fin;
    char pattern[30] = "*.*";
    int width, height;
    char bmpExt[5] = ".BMP";
    char gifExt[5] = ".GIF";
    char jpgExt[5] = ".JPG";
    char pngExt[5] = ".PNG";
    
    //Get the directory listing
    dHandle = _findfirst ( pattern, &aFile );
    
    if ( dHandle == -1 )
    {
        return;
    }
    
    do
    {
        //Check to see if the main file is not a sub directory or not
        if ( ! ( aFile.attrib & _A_SUBDIR ) )
        {
            //Open the main file in binary mode
            fin.open ( aFile.name, ios::in | ios::binary );
            
            //Error check to see if the file opened or not
            if ( !fin )
            {
                cout << "File was not able to be opened";
            }
            else
            {
                //Check to see if the file is a BMP and perform the tasks to
                //extract the width and height and rename it
                if ( isBMP ( fin ) == true )
                {
                    findBMPWidth ( width, fin );
                    findBMPHeight ( height, fin );
                    fin.close();
                    rename_file ( aFile.name, width, height, bmpExt );
                }
                
                //Check to see if the file is a GIF and perform the tasks to
                //extract the width and height and rename it
                if ( isGIF ( fin ) == true )
                {
                    findGIFWidth ( width, fin );
                    findGIFHeight ( height, fin );
                    fin.close();
                    rename_file ( aFile.name, width, height, gifExt );
                }
                
                //Check to see if the file is a JPG and perform the tasks to
                //extract the width and height and rename it
                if ( isJPG ( fin ) == true )
                {
                    fin.close();
                    rename_JPG ( aFile.name, jpgExt );
                }
                
                //Check to see if the file is a PNG and perform the tasks to
                //extract the width and height and rename it
                if ( isPNG ( fin ) == true )
                {
                    findPNGWidth ( width, fin );
                    findPNGHeight ( height, fin );
                    fin.close();
                    rename_file ( aFile.name, width, height, pngExt );
                }
                
            }
            
            //Close the file
            fin.close();
            
        }
    }
    while ( _findnext ( dHandle, &aFile ) == 0 );
    
    //Close the directory listing
    _findclose ( dHandle );
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function renames the files that are brought in. This will create a new 
* name with the parameters that are passed in.  The oldname, width (which can 
* be changed), height (which can be changed), and the extension of what type of
* file it is. The function then error checks to see if the rename function 
* actually works or not.  The function returns nothing but it will be brought 
* to the directory function if it works properly.
*
* @param[in]         oldname
* @param[in, out]    width
* @param[in, out]    height
* @param[in]         extension
*
***************************************************************************/
void rename_file ( char *oldname, int &width, int &height,
                   char extension[] )
{
    //Declare variables
    char string_width[40] = "";
    char string_height[40] = "";
    string new_name = "";
    string underscore = "_";
    string x = "x";
    //Rename the file to add the width, height, and extention onto the file
    new_name = oldname + underscore + to_string ( width ) + x + to_string (
                   height )
               + extension;
               
    //If the rename file works, continue through the program
    if ( rename ( oldname, new_name.c_str() ) == 0 )
    {
        return;
    }
    
    //If the file is not able to be renamed, output error message
    else
    {
        cout << "Unable to rename: " << oldname << "==>" <<
             new_name;
    }
    
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function renames the JPG files so that it doesn't show the width and 
* height like the other three picture forms. This function brings in the 
* oldname of the file to be renamed and the extension in which in needs to be 
* appended on the end, in this case ".JPG."  The function adds the old name and
* extension together and sends it back to the directory lising file to be 
* outputted.  It will also error check to see if the rename function actually 
* worked or if the file cannot be renamed.  The file doesn't return anything in
* order for it to work.
*
* @param[in]         oldname
* @param[in]         extension
*
***************************************************************************/
void rename_JPG ( char *oldname, char extension[] )
{
    //Initilize the variables
    string new_name = "";
    //Assign the newname and the extension together
    new_name = oldname;
    new_name += extension;
    
    //Check if the rename file works, if so, continue the program
    if ( rename ( oldname, new_name.c_str() ) == 0 )
    {
        return;
    }
    //If the file cannot be named, output error message
    else
    {
        cout << "Unable to rename: " << oldname << "==>" <<
             new_name;
    }
    
}