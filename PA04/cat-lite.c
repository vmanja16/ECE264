#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)

{
/*------------------------------HELP STATEMENT-----------------------------------------------*/
    int I = 1, HELPSTATEMENT = 0;    // Help statement identifier
    while( I < argc)
        {
        if (strcmp(argv[I], "--help") == 0) {       
           printf("Usage: cat-lite [--help] [FILE]...\nWith no FILE, or when FILE is -, read standard input.\n\nExamples:\ncat-lite README   Print the file README to standard output.\ncat-lite f - g    Print f's contents, then standard input,\n then g's contents.\ncat-lite          Copy standard input to standard output.\n");    
           HELPSTATEMENT = 1;
           }

        I++;
         }
    if (HELPSTATEMENT ==1) { return EXIT_SUCCESS;}

/*------------------------PRINTING FILES-------------------------*/

    I = 1;
    FILE * fp;
    char buffer[9000];
    while ( I < argc)  

        {
        

        if (strcmp( argv[I], "-" ) == 0 )
            {
            fp = fopen("stdin", "r");
            while (feof(fp) == 0)
                {
                fgets(buffer, 9000, fp);
                printf("%s", buffer);
                }
            fclose(fp);
            I++;
            continue;
            }

        fp = fopen(argv[I], "r");

        if (fp == NULL)                               //Checks for erroneous filename 
            {                                         
            printf("cat cannot open %s\n", argv[I]);  
            
            I++;                                      
            continue;                                 
            }


        if (strcmp( argv[I], "-" ) == 0 )
            {   
            fp = fopen("stdin", "r");
            while (feof(fp) == 0)
                {
                fgets(buffer, 9000, fp);
                printf("%s", buffer);
                }
            fclose(fp);
            I++;
            continue;
            }

            while (feof(fp) == 0)
                {
                fgets(buffer, 9000, fp); 
                printf("%s", buffer);
                }
            fclose(fp);
        
          






        I++;
        }





    return EXIT_SUCCESS;
}
