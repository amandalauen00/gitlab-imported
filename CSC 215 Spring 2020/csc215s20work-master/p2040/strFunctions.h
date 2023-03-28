#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

#ifndef __STRFUNCTIONS__H
#define __STRFUNCTIONS__H 

enum TRIMMETHOD{ BOTH, FRONT, BACK};

//write the prototype for the ctrim function here

    char ctrim(char phrase[100], TRIMMETHOD trim);

//write the prototype for the strim function here.

    void strim(string &s,TRIMMETHOD trim);

#endif
