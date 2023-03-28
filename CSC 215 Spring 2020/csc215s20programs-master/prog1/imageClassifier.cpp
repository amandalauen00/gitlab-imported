/** ***************************************************************************
* @file
***************************************************************************/
#include "imageClassifier.h"
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines if the file that is being compared is a BMP function
* .  If it is, then the file seeks to the beginning of the file and starts at 
* the value of 0.  It then reads the first 2 bytes and compares it to the file 
* to see if the file contains the letters "BM."  If so, then the function will 
* return true.  If not, then the function will return false.  The function 
* returns either true or false if it is ran properly.
*
* @param[in, out]    fin    - This variable holds the current file name
*
* @returns true or false if the function runs successful
*
***************************************************************************/
bool isBMP ( ifstream &fin )
{
    //Initilize the empty num array
    unsigned char num[3] = "";
    //Seek to the first integer from the beginning
    fin.seekg ( 0, ios::beg );
    //Read in the number of bytes into the num array
    fin.read ( ( char * ) &num, 2 );
    
    //Compare if the num array has the letters "BM" or not
    if ( strcmp ( ( char * ) num, "BM" ) == 0 )
    {
        return true;
    }
    
    return false;
    
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines if the file in question is a GIF or not.  This 
* function will first seek to the beginning of the file and read in the first 6
* bytes, leading to the 7th byte to determine if that byte matches up with the
* expressions "GIF89a" or (GIF87a."  If it does, then the function will return 
* true.  If not, then the function will return false.  This function returns 
* true or false if working properly.
*
* @param[in, out]    fin    -  This variable holds the current file in which
                               needs to be changed
*
* @returns true or false if the function runs successful
*
***************************************************************************/
bool isGIF ( ifstream &fin )
{
    //Initilize the empty num array
    unsigned char num[7] = "";
    //Seek to the beginning of the file to the very first integer
    fin.seekg ( 0, ios::beg );
    //Read in the number of bytes into the num array
    fin.read ( ( char * ) &num, 6 );
    
    //Compare the num array and see if it has the phrases "GIF89a" or "GIF87a"
    //or not
    if ( strcmp ( ( char * ) num, "GIF89a" ) == 0 ||
            strcmp ( ( char * ) num, "GIF87a" ) == 0 )
    {
        return true;
    }
    
    return false;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines if the file in question is a JPG or not.  It will do
* this by seeking to the beginning of the file and starting with the value in 
* the 0th integer.  It will then read in the first two bytes and see if these 
* two bytes have the first and second coordinates which are intilized as (255, 
* 216) and (255, 217).  The also include the null terminator because there 
* shouldn't be any other values in those pairs.  If the file has these 
* coordinates, the function will return true.  If not, then the function will 
* return false.  This function returns true or false if it runs properly.
*
* @param[in, out]    fin   - This variable holds the current file in which
                             needs to be changed
*
* @returns true or false if the function runs successful
*
***************************************************************************/
bool isJPG ( ifstream &fin )
{
    //Initilize the empty num array
    unsigned char num[3] = "";
    //Initilize the coordinates needed for JPG
    char first_cord[3] = {char ( 255 ), char ( 216 ), '\0' };
    char sec_cord[3] = {char ( 255 ), char ( 217 ), '\0'};
    //Seek to the beginning of the file towards the very first integer
    fin.seekg ( 0, ios::beg );
    //Read in a certain number of bytes into the num array
    fin.read ( ( char * ) &num, 2 );
    
    //Compare the num array to see if it has the coordinates needed for a JPG
    //or not
    if ( strcmp ( ( char * ) num, first_cord ) == 0 ||
            strcmp ( ( char * ) num, sec_cord ) == 0 )
    {
        return true;
    }
    
    return false;
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines if the file in question is a PNG file.  To do this, 
* the function seeks to the beginning of the file and reads in the first 8 
* bytes of the file. If the bytes contain the values (136, 80, 78, 71, 13, 10, 
* 26, 10), then, the function will return true.  If not, then the function 
* returns false. This function returns true or false when ran successfully.
*
* @param[in, out]    fin    - This variable holds the current file that is
*                             being compared
*
* @returns true or false if the function runs successful
*
***************************************************************************/
bool isPNG ( ifstream &fin )
{
    //Initilize the PNG bytes
    unsigned char bytes[9] = { ( unsigned char ) 137, ( unsigned char ) 80,
                               ( unsigned char ) 78, ( unsigned char ) 71,
                               ( unsigned char ) 13, ( unsigned char ) 10,
                               ( unsigned char ) 26, ( unsigned char ) 10, '\0'
                             };
    //Initilize the empty num array
    unsigned char num[9] = "";
    //Seek to the beginning of the list towards the very first integer
    fin.seekg ( 0, ios::beg );
    //Read in the number of bytes into the num array
    fin.read ( ( char * ) &num, 8 );
    
    //Compare the num array with the PNG bytes to see if they are there or not
    if ( strcmp ( ( char * ) num, ( char * ) bytes ) == 0 )
    {
        return true;
    }
    
    return false;
}