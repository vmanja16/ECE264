# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "answer05.h"
// PARTIONS of Integers

/*--------------------ALL------------------------*/

void partitionAll(int value) // CODE NEARLY SAME AS COURSE TEXT
                             // CREDIT TO PROFESSOR LIU

{

    int Original = value;

    if (value > 1); {printf("= ");}

    void PrintFunction ( int * array, int Length, int original) // Printing arrays
        {
        
        int I;
        for ( I = 0; I < (Length - 1); I++)
            {
            printf("%d + ", array[I]);
            }
        if (array[Length -1] == original) {printf("%d\n", array[Length-1]);
            return;}
        printf("%d\n= ", array[Length-1]);    // printing end of the partition line
        }

    
    void PartitionFunction ( int * Array, int Index, int Value, int original)
        {
        int I;
        
        if (Value == 0)  // Partition is Over
            { 
            PrintFunction(Array, Index, original);
            return;
            }
        
        for ( I = 1; I <= Value; I++)
            {
            Array[Index] = I;
            PartitionFunction ( Array, Index + 1, Value - I, original); // Recursive Call
            }

        }

    int Array[value]; // creating array for integers                 
    PartitionFunction ( Array, 0, value, Original); // Initial Call of Function


    
  
}

/*----------------------INCREASING------------------*/

void partitionIncreasing(int value)

{

    int Original = value;
        
    if (value > 1); {printf("= ");}
        
    void PrintFunction ( int * array, int Length, int original) // Printing arrays
        {
            
        int I;

         for ( I = 0; I < (Length - 1); I++)
            {
            if(array[I+1] <= array[I]) {return;}
            }

        for ( I = 0; I < (Length - 1); I++)
            {
            printf("%d + ", array[I]);
            }
        if (array[Length -1] == original) {printf("%d\n", array[Length-1]);
            return;}
        printf("%d\n= ", array[Length-1]);    // printing end of the partition line
        }

    
    void PartitionFunction ( int * Array, int Index, int Value, int original)  
        {
        int I;

        if (Value == 0)  // Partition is Over
            {
            PrintFunction(Array, Index, original);
            return;
            }

        for ( I = 1; I <= Value; I++)
            {
            Array[Index] = I;
            PartitionFunction ( Array, Index + 1, Value - I, original); // Recursive Call
            }
    
        }
    
    int Array[value]; // creating array for integers
    PartitionFunction ( Array, 0, value, Original); // Initial Call of Function

}

/*----------------------------DECREASING----------------*/

void partitionDecreasing(int value)

{

     int Original = value;
             
    if (value > 1); {printf("= ");}
         
    void PrintFunction ( int * array, int Length, int original) // Printing arrays
        {
    
        int I;
        
         for ( I = 0; I < (Length - 1); I++)
            {
            if(array[I+1] >= array[I]) {return;}
            }

        for ( I = 0; I < (Length - 1); I++)
            {
            printf("%d + ", array[I]);
            }
        if (array[Length -1] == original) {printf("%d\n", array[Length-1]);
            return;}
        printf("%d\n= ", array[Length-1]);    // printing end of the partition line
        }
         
    
    void PartitionFunction ( int * Array, int Index, int Value, int original)
        {
        int I;
        
        if (Value == 0)  // Partition is Over
            {
            PrintFunction(Array, Index, original);
            return;
             }
        
        for ( I = 1; I <= Value; I++)
            {
            Array[Index] = I;
            PartitionFunction ( Array, Index + 1, Value - I, original); // Recursive Call
            }
         
        }
        
    int Array[value]; // creating array for integers
    PartitionFunction ( Array, 0, value, Original); // Initial Call of Function
             
}

/*-----------------------------ODD-------------------------*/

void partitionOdd(int value)

{
    int Original = value;
            
    if (value > 1); {printf("= ");}
        
    void PrintFunction ( int * array, int Length, int original) // Printing arrays
        {
         
        int I;
        for ( I = 0; I < (Length); I++)
            {
            if ( array[I] % 2 == 0) { return;}
            }
        for ( I = 0; I < (Length - 1); I++)
            {
            printf("%d + ", array[I]);
            } 
        if (array[Length -1] == original) {printf("%d\n", array[Length-1]);
            return;}
        if (array[Length -2] == (original-1) ) {printf("%d\n", array[Length-1]);
            return;}
        printf("%d\n= ", array[Length-1]);    // printing end of the partition line
        }
            
             
    void PartitionFunction ( int * Array, int Index, int Value, int original)
        {
        int I;
            
        if (Value == 0)  // Partition is Over
            {
            PrintFunction(Array, Index, original);
            return;
            } 
        
        for ( I = 1; I <= Value; I++)
            {
            Array[Index] = I;
            PartitionFunction ( Array, Index + 1, Value - I, original); // Recursive Call
            }
        
        }
             
    int Array[value]; // creating array for integers
    PartitionFunction ( Array, 0, value, Original); // Initial Call of Function
         
        

}

/*---------------------EVEN---------------------------*/

void partitionEven(int value)

{
     int Original = value;

    if ((value % 2) == 0) {printf("= ");}

    void PrintFunction ( int * array, int Length, int original) // Printing arrays
        {

        int I;
        for ( I = 0; I < (Length); I++)
            {
            if ((array[I] % 2) != 0) {return;}
            }
        for ( I = 0; I < (Length - 1); I++)
            {
            printf("%d + ", array[I]);
            }
        if (array[Length -1] == original) {printf("%d\n", array[Length-1]);
            return;}
        printf("%d\n= ", array[Length-1]);    // printing end of the partition line
        }


    void PartitionFunction ( int * Array, int Index, int Value, int original)
        {
        int I;

        if (Value == 0)  // Partition is Over
            {
            PrintFunction(Array, Index, original);
            return;
            }

        for ( I = 1; I <= Value; I++)
            {
            Array[Index] = I;
            PartitionFunction ( Array, Index + 1, Value - I, original); // Recursive Call
            }

        }
    
     int Array[value]; // creating array for integers
     PartitionFunction ( Array, 0, value, Original); // Initial Call of Function
         

}
/*-----------------ODD-EVEN--------------------------*/

void partitionOddAndEven(int value)

{

    int Original = value;

    if (value > 1); {printf("= ");}

    void PrintFunction ( int * array, int Length, int original) // Printing arrays
        {

        int I;
        for ( I =0; I < (Length-1); I++)
            {
            if ( (array[I+1] % 2) == (array[I] % 2) ) {return;} 
            }
        for ( I = 0; I < (Length - 1); I++)
            {
            printf("%d + ", array[I]);
            }
        if (array[Length -1] == original) {printf("%d\n", array[Length-1]);
            return;}
        printf("%d\n= ", array[Length-1]);    // printing end of the partition line
        }


    void PartitionFunction ( int * Array, int Index, int Value, int original)
        {
        int I;

        if (Value == 0)  // Partition is Over
            {
            PrintFunction(Array, Index, original);
            return;
            }

        for ( I = 1; I <= Value; I++)
            {
            Array[Index] = I;
            PartitionFunction ( Array, Index + 1, Value - I, original); // Recursive Call
            }

        }

    int Array[value]; // creating array for integers
    PartitionFunction ( Array, 0, value, Original); // Initial Call of Function

}

/*--------------------------PRIME-----------------------*/

void partitionPrime(int value)

{
   // int Array[value]; //Creat array for integers

}


//int main(void) {partitionOddAndEven(9);
//   printf("\n\n\n");
//   partitionOddAndEven(8);
//   printf("\n\n\n");
//   partitionOddAndEven(1);
//   return 0;}
