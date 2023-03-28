/** ***************************************************************************
* @file
***************************************************************************/
#ifndef __IMAGEDIMENSIONS__H__
#define __IMAGEDIMENSIONS__H__
#include <fstream>
#include <iostream>
using namespace std;

//Function prototypes for the height and widths
void findBMPWidth ( int &width, ifstream &fin );
void findBMPHeight ( int &height, ifstream &fin );
void findGIFWidth ( int &width, ifstream &fin );
void findGIFHeight ( int &height, ifstream &fin );
void findPNGWidth ( int &width, ifstream &fin );
void findPNGHeight ( int &height, ifstream &fin );

#endif
