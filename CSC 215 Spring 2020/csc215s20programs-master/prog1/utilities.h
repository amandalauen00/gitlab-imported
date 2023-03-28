/** ***************************************************************************
* @file
***************************************************************************/
#ifndef __UTILITIES__H__
#define __UTILITIES__H__

#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <io.h>
#include "imageClassifier.h"
#include "imageDimensions.h"

using namespace std;

//Function prototypes that are not main, classifiers, or dimensions
void rename_file ( char *oldname, int &width, int &height,
                   char extension[] );
void rename_JPG ( char *oldname, char extension[] );
void dirlisting();


#endif
