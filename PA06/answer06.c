#include "answer06.h"
#include <stdio.h>

void print_directions(char** maze, int w, int h) 



{

char ** Maze = maze; //Assigning Maze to maze
char  *Current = &Maze[0][0]; // Assigning Character pointer to left corner

/*-----------------FINDING ENTRANCE--------------------*/

    int I =0;
    

    while ( Maze[0][I] == 'X') 
        {
   			I++;    	
        }
    Current = &Maze[0][I]; // Current points to opening of maze


    printf("%d\n", I );
    printf("%c\n", *Current);

/*-------------------------------------------------------*/






}
