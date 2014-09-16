#include "answer03.h"
#include <stdlib.h>
#include <string.h>

/*-----------------------String Concatenation-------------------------------*/

char * strcat_ex(char * * dest, int * n, const char *src) 

{

    char * buffer;

    if( (*dest == NULL) || (strlen(src) + strlen(*dest) + 1 > *n) ) //Is dest too small? 
    { 
    
       // If dest is null, don't include its lenght in buffer, revalue n

        if (*dest == NULL) { 
            buffer = (char *) malloc(1 + 2 * strlen(src));
            *n = (1 + 2 * strlen(src) ); } 

        else 
            { 
            buffer = (char *) malloc( 1 + 2 * (strlen(*dest) + strlen(src)) );
            *n = ( 1 + 2 * (strlen(*dest) + strlen(src)) ); }


        strcpy(buffer,*dest);
        
        free(*dest);     //Freeing dest's memory
 
        *dest = buffer;  // Pointing dest to buffer
        

        strcat (*dest, src);   //Concatenating src to dest

    }
    
    else  //Dest is big enough for direct concatenation

    {
    strcat (* dest, src);
    }       
    
    return *dest;
}



char * * explode(const char * str, const char * delims, int * arrLen)


{

    return 0;
}


char * implode(char * * strArr, int len, const char * glue)

{

    return *strArr;
}


void sortStringArray(char * * arrString, int len)

{

}


void sortStringCharacters(char * str)

{

}



void destroyStringArray(char * * strArr, int len)

{

}
