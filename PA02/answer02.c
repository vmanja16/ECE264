#include "answer02.h"

/*------------------------------Length Finder-----------------------*/
 
// Length of C string 'str', excluding the terminating null byte ('\0')


size_t my_strlen(const char * str) {

	int Count = 0, I=0;
        

	for(I=0;str[I] != '\0'; I++) 
            {
            ++Count;
            }
   
	return Count;

}


/*--------------Character Counter--------------------------*/

int my_countchar(const char * str, char ch) 
    {
    int I=0, Count =0;

    while (str[I] != '\0')
        {
            if (str[I] == ch)
               {
                   ++Count;
               }
        ++I;
        }
    return Count;
}

/*----------------Left Character Finder------------------*/

char * my_strchr(const char * str, int ch)

    {              
        int I=0;
        char * Character = NULL, * Ptr = str;               
        
        while((str[I] != '\0') & (str[I] != ch))
            {
            ++I;
 	    }
            
            if (str[I] == ch)
                {
                Character = Ptr;
                Character = Character + I;
                }

        return (char *) Character;        
    }    

/*-------------Right Character Finder-----------------------*/


char * my_strrchr(const char * str, int ch)

    { 

    int I = 0;
    char * Character = NULL, * Ptr = str, * Ptr1 = str;
             
     while(str[I] != '\0') 
            {
            ++I;
            }

    Ptr1 = Ptr1 + I;

    while ((I != 0) && (str[I] != ch))                  
            {   
            --I;
            }
    
            if (str[I] == ch)
                {
                Character = Ptr;
                Character = Character + I;
                }
        
        return (char *) Character;        
    }    

char * my_strstr(const char * haystack, const char * needle)
    {              
    return 0;   
        
    }    


char * my_strcpy(char * dest, const char * src)

    {              
    return 0;   
        
    }    

char * my_strcat(char * dest, const char * src)

    {              
    return 0;   
        
    }    


int my_isspace(int ch)
    {              
    return 0;   
        
    }    

int my_atoi(const char * str)

    {  
    return 0;

    }
