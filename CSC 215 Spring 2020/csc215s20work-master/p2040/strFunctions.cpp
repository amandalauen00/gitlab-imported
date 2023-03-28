#include "strFunctions.h"

char ctrim(char phrase[100], TRIMMETHOD trim)
{
    int SIZE = (int)strlen(phrase);
    int i = 0;
    char *ptr = nullptr;
    ptr = phrase;

    if (trim == BACK || trim == BOTH) 
    {
        for (i = (SIZE - 1); i >= 0 && (isspace(phrase[i])); i--);

        {
            phrase[i + 1] = '\0';
        }
    }
    SIZE = (int)strlen(phrase);
    if (trim == FRONT || trim == BOTH)
    {
        i = 0;
        while (i < SIZE && isspace(phrase[i])  )
        {
            i++;
        }
        ptr = &phrase[i];
        strcpy( phrase, ptr);
    }

    return 0;
}






void strim(string &s, TRIMMETHOD trim)
{
    string::size_type idx;

    if (trim == BACK || trim == BOTH)
    {
        if(!s.empty())
        {
            idx = s.find_last_not_of(" \n\t\r\v\f");
            if (idx != string::npos)
            {
                s = s.substr(0, idx + 1);
            }
            else
            {
                s.clear();
            }
        }  
    }

    if (trim == FRONT|| trim == BOTH)
    {
        if(!s.empty())
        {
            idx = s.find_first_not_of(" \n\t\r\v\f");
            if (idx != string::npos)
            {
                s = s.substr(idx, s.length());
            }
            else
            {
                s.clear();
            }
        }
    }
}