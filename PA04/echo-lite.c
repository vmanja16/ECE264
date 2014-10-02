#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)

{
    if ( argc == 1) { 
        printf("\n");
        return EXIT_SUCCESS;}
    
    int I =1;

    while ( I < argc )
        {
        printf("%s ", argv[I]);
        I++;
        }





    return EXIT_SUCCESS;
}
