/** ***************************************************************************
* @file
***************************************************************************/
#include "imageDimensions.h"
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines the width of the BMP file.  To do this, the function
* seeks to the beginnig of the integer and looks for the 18th integer (19th 
* byte) and then the function reads that value into the num array with the 
* number 4 because it is stored in the next 4 bytes. The function then checks 
* if it is within the spectrum of being greater than 0 starting at the value 3.
* If so, the the width is found by shifting left 8 and taking the width and 
* "oring" it with the num array with the index i-1.  The function returns 
* nothing when the program runs successfully.
*
* @param[in, out]    width - This variable holds the width of the file
* @param[in, out]    fin  - This variable holds the current file being renamed
*
***************************************************************************/
void findBMPWidth ( int &width, ifstream &fin )
{
    //Initilize num array
    unsigned char num[5];
    //Seek to the 18th integer from the beginning
    fin.seekg ( 18, ios::beg );
    //Read in the certain bytes into the num array
    fin.read ( ( char * ) &num, 4 );
    //Compare both in order to retrive the width
    for ( int i = 3; i > 0; i-- )
    {
        width = ( int ) num[i] << 8;
        width |= num[i - 1];
    }
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines the height of the BMP file.  To do this, the 
* function seeks to the beginnig of the integer and looks for the 22nd integer
* (23rd byte) and then the function reads that value into the num array with 
* the number 4 because it is stored in the next 4 bytes. The function then 
* checks if it is within the spectrum of being greater than 0 starting at the 
* value 3.  If so, the the width is found by shifting left 8 and taking the 
* height and "oring" it with the num array with the index i-1.  The function 
* returns nothing when the program runs successfully.
*
* @param[in, out]    height - This variable holds the height of the file
* @param[in, out]    fin  - This variable holds the current file being renamed
*
***************************************************************************/
void findBMPHeight ( int &height, ifstream &fin )
{
    //Initilize num array
    unsigned char num[5];
    //Seek to the 23rd integer from the beginning
    fin.seekg ( 22, ios::beg );
    //Read in the certain bytes into the num array
    fin.read ( ( char * ) &num, 4 );
    //Compare both in order to retrieve the height
    for ( int i = 3; i > 0; i-- )
    {
        height = ( int ) num[i] << 8;
        height |= num[i - 1];
    }
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines the width of the GIF file.  To do this, the function
* seeks to the beginnig of the integer and looks for the 6th integer (7th byte)
* and then the function reads that value into the num array with the number 2 
* because it is stored in the next 2 bytes. The function then checks if it is 
* within the spectrum of being greater than 0 starting at the value 1.  If so,
* the the width is found by shifting left 8 and taking the width and "oring" it
* with the num array with the index i-1.  The function returns nothing when the
* program runs successfully.
*
* @param[in, out]    width - This variable holds the width of the file
* @param[in, out]    fin  - This variable holds the current file being renamed
*
***************************************************************************/
void findGIFWidth ( int &width, ifstream &fin )
{
    //Initilize the num array
    unsigned char num[3];
    //Seek to the location of the 7th integer from the beginning
    fin.seekg ( 6, ios::beg );
    //Read in the certain bytes into the num array
    fin.read ( ( char * ) &num, 2 );
    //Compare both of them in order to get width
    for ( int i = 1; i > 0; i-- )
    {
        width = ( int ) num[i] << 8;
        width |= num[i - 1];
    }
    
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines the heignt of the GIF file.  To do this, the 
* function seeks to the beginnig of the integer and looks for the 8th integer 
* (9th byte) and then the function reads that value into the num array with the
* number 2 because it is stored in the next 2 bytes. The function then checks 
* if it is within the spectrum of being greater than 0 starting at the value 1.
* If so, the the width is found by shifting left 8 and taking the height and 
* "oring" it with the num array with the index i-1.  The function returns 
* nothing when the program runs successfully.
*
* @param[in, out]    height - This variable holds the height of the file
* @param[in, out]    fin  - This variable holds the current file being renamed
*
***************************************************************************/
void findGIFHeight ( int &height, ifstream &fin )
{
   //Inililize the num array
    unsigned char num[3];
    //Seek to the location of the 9th integer from the beginning
    fin.seekg ( 8, ios::beg );
    //Read in the certain number of bytes into the num array
    fin.read ( ( char * ) &num, 2 );
    //Compare both in order to get the height
    for ( int i = 1; i > 0; i-- )
    {
        height = ( int ) num[i] << 8;
        height |= num[i - 1];
    }
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines the width of the PNG file.  To do this, the function
* seeks to the beginnig of the integer and looks for the 16th integer (17th 
* byte) and then the function reads that value into the num array with the 
* number 4 because it is stored in the next 4 bytes. The function then checks 
* if it is within the spectrum of being less than 3 starting at the value 0.  
* If so, the the width is found by shifting left 8 and taking the width and 
* "oring" it with the num array with the index i+1.  The function returns 
* nothing when the program runs successfully.
*
* @param[in, out]    width - This variable holds the width of the file
* @param[in, out]    fin  - This variable holds the current file being renamed
*
***************************************************************************/
void findPNGWidth ( int &width, ifstream &fin )
{
    //Initilize the num array
    unsigned char num[5];
    //Seek to the location of the 17th integer from the beginning
    fin.seekg ( 16, ios::beg );
    //Read in the number of bytes into the num array
    fin.read ( ( char * ) &num, 4 );
    //Compare both in order to get the width
    for ( int i = 0; i < 3; i++ )
    {
        width = num[i] << 8;
        width |= num[i + 1];
    }
}
/** ***************************************************************************
* @author Amanda Lauen
*
* @par Description: 
* This function determines the height of the PNG file.  To do this, the 
* function seeks to the beginnig of the integer and looks for the 20th integer 
* (21st byte) and then the function reads that value into the num array with 
* the number 4 because it is stored in the next 4 bytes. The function then 
* checks if it is within the spectrum of being less than 3 starting at the 
* value 0.  If so, the the width is found by shifting left 8 and taking the 
* height and "oring" it with the num array with the index i+1.  The function 
* returns nothing when the program runs successfully.
*
* @param[in, out]    height - This variable holds the height of the file
* @param[in, out]    fin  - This variable holds the current file being renamed
*
***************************************************************************/
void findPNGHeight ( int &height, ifstream &fin )
{
    //Initilize the num array
    unsigned char num[5];
    //Seek to the location of the 21st integer from the beginning
    fin.seekg ( 20, ios::beg );
    //Read in the number of bytes into the num array
    fin.read ( ( char * ) &num, 4 );
    //Compare both in order to get the height
    for ( int i = 0; i < 3; i++ )
    {
        height = num[i] << 8;
        height |= num[i + 1];
    }
}