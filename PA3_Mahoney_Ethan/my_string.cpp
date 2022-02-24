#include <iostream>
#include "my_string.h"


//Function counts each letter in a string then returns the amount of letters minus the null character
size_t myStringLength(const char *str)
{
    int count = 0;

    while(*str != '\0')
    {
        count++;
        str++;
    }

    return count;
}

//Function compares strings of two different sources and returns the difference or similarity between the sources
int myStringCompare(const char *str1, const char *str2)
{
    while(*str1 != '\0' && *str2 != '\0')
    {
        if(*str1 > *str2)
        {
            return 1;
        }
        else if(*str1 < *str2)
        {
            return -1;
        }
        else
        {
            str1++;
            str2++;
        }
    }
    return 0;
}

//Function takes the string of one source and copies it into another source, returning a pointer to the specific string
char *myStringCopy(char *destination, const char *source)
{
    while(*source != '\0')
    {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
    
    return destination;
}

//Function appends the contents of a source to another and then returns a pointer to the new content
char *myStringCat(char *destination, const char *source)
{
    while(*destination != '\0')
    {
        destination++;
    }
    
    while(*source != '\0')
    {
        *destination = *source;
        source++;
        destination++;
    }

    *destination = '\0';
 
    return destination;
}
