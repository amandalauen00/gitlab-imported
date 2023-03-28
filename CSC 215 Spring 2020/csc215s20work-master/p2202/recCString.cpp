#include "recCString.h"

int recCmp ( char *lhs, char *rhs, int index )
{
    int diff;
    
    if ( lhs[index] == '\0' && rhs[index] == '\0')
    {
        return 0;
    }

    diff = lhs[index] - rhs[index];
    if (diff == 0)
    {
        diff = recCmp(lhs, rhs, ++index);
    }
    return diff;
    
}

void fixTitle ( char *title, int index )
{
    if (title[index] == '\0')
    {
        return;
    }
    if(index == 0 && isalpha(title[index]))
    {
        title[index] = toupper(title[index]);
    }
    if (index > 0 && title[index - 1] == ' ')
    {
        title[index] = toupper(title[index]);
    }

    fixTitle(title, index + 1);
}