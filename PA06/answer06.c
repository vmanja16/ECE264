#include "answer06.h"
#include <stdio.h>

void print_directions(char** maze, int w, int h) 

{

 printf("w = %d, h = %d... hopefullR 9 and 7\n", w, h);
char ** Maze = maze; //Assigning Maze to maze

/*-----------------FINDING ENTRANCE--------------------*/

    int I = 0, J = h-1, EC = 0, ER = 0;
    
    printf("%d,%d\n", EC, ER);
    I = 0;
    J = 0;
    while ( Maze[J][I] == 'X') 
        {
   			I++;    	// Entrance C Coordinate
        }

/*---------------------WALLS AND BOUNDARY IDENTIFIER----------*/
   int Available(char ** Maze, int R, int C, int w, int h)
        {
        if ( (C > w) || (C < 0)) {return 0;} //check C in bounds
        if ( (R > h) || (R < 0)) {return 0;} // check R in bounds
        if ( Maze[R][C] == 'X') {return 0;} // check if wall
        if ( Maze[R][C] == 'O') {return 0;} // check if past
        return 1;
        }
/*--------------------Recursive Function-----------------------*/
   void PathFinder(char ** Maze, int R, int C, int w,int h)
        {

        if (Available(Maze, R, C,w,h) == 0){return;}//check if closed
    	Maze[R][C] = 'O'; // MARKING SPOT
        //Check South
        if (Available(Maze, R+1, C,w,h) == 1)
        {
            printf("S 1\n");
            PathFinder(Maze,R+1,C,w,h);
            printf("N 1\n");  
        }
    	//check East
        if (Available(Maze, R, C+1,w,h) == 1)
        {
            printf("E 1\n");
            PathFinder(Maze,R,C+1,w,h);
            printf("W 1\n");
        }
         //Check North
        if (Available(Maze, R-1, C, w, h) == 1)
        {
            printf("N 1\n");
            PathFinder(Maze,R-1,C,w,h);
            printf("S 1\n");           
        }
    	//Check West;
    	if (Available(Maze, R, C-1, w, h) == 1)
        {
            printf("W 1\n");
            PathFinder(Maze, R, C-1, w, h);
            printf("E 1\n");
    	}
    return; 
   	    }
     PathFinder(Maze, 0, I, w-1, h-1); // CALLING FUNCTION
}
