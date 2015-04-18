#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void quickSort( int a[], int lb, int ub);
int partition( int a[], int Left, int Right); 



typedef struct Vert {
	float ID, Age, Gender, MaritalStatus, Race, BirthPlace, Language,
		  Occupation, Income;
    struct Vert * next;
    float * ULAB;
} Vertex;





int main(void)
{

FILE * fp;
float Users = 0, Thresh1 = 0, Thresh2 = 0, QueryNode = 0, Alpha = 0, Maximum = 0;
int i = 0, j = 0, Query3Array1[100000], Query3Array2[100000];
int Count31 = 0, Count32 = 0;
Vertex * ptr1 = NULL, * ptr2 = NULL;



/*-Initializing Vertex List Header-*/
							//
Vertex Header;				//
Header.ID = 0;				//
Header.Age = 0;				//
Header.Gender = 0;			//		
Header.MaritalStatus = 0;	//
Header.Race = 0;			//
Header.BirthPlace = 0;		//
Header.Language = 0;		//
Header.Occupation = 0;		//
Header.Income=0;            //
Header.next = NULL;         //
/*-------------------------------*/

fp = fopen("input.txt", "r");

// Scanning in First Row of values
fscanf(fp,"%f, %f, %f, %f, %f", &Users, &Thresh1, &Thresh2, &QueryNode, &Alpha);

printf("%f %f %f %f %f\n", Users, Thresh1, Thresh2, QueryNode, Alpha);
 

/*----------------CREATING LINKED LIST OF VERTICES-------------------------*/

// Creating initial Node	
Header.next = malloc(sizeof(Vertex));
ptr1 = Header.next;                      // ptr1 initialized to header.next
fscanf(fp, "%f, %f, %f, %f, %f, %f, %f, %f, %f",
   	   &(ptr1->ID), &(ptr1->Age), &(ptr1->Gender), &(ptr1->MaritalStatus), 
   	   &(ptr1->Race),
   	   &(ptr1->BirthPlace), &(ptr1->Language), &(ptr1->Occupation), 
   	   &(ptr1->Income) );

// Linking Nodes                                            
for ( i = 0; i < Users-1; i++)
{
	ptr1->next = malloc(sizeof(Vertex));
	ptr1 = ptr1->next;
    fscanf(fp, "%f, %f, %f, %f, %f, %f, %f, %f, %f",
   	&(ptr1->ID), &(ptr1->Age), &(ptr1->Gender), &(ptr1->MaritalStatus), 
   	&(ptr1->Race),
   	&(ptr1->BirthPlace), &(ptr1->Language), &(ptr1->Occupation), 
   	&(ptr1->Income) );
    ptr1->next = NULL;
}
                       /**/
ptr1 = Header.next;
for (i = 0; i < Users; i++)
{
	printf("%.3f %.3f %.3f %.3f %.3f %.3f %3.f %.3f %.3f\n",
   	ptr1->ID, ptr1->Age, ptr1->Gender, ptr1->MaritalStatus, ptr1->Race,
   	ptr1->BirthPlace, ptr1->Language, ptr1->Occupation, ptr1->Income);
   	ptr1 = ptr1->next;
}
 
 // FINISHED Linked List of Vertices 


 /*                  CREATING ARRAYS OF ULAB                                 */
ptr1 = Header.next;

while (ptr1 != NULL)
{
    ptr2 = Header.next;  // set ptr2 to beginning;
	ptr1->ULAB = malloc(sizeof(float) * (int)(Users) ); // allocate space for weights
	i = 0;
	while (ptr2 != NULL)
	{
      ptr1->ULAB[i] = pow( pow(ptr1->Age - ptr2->Age, 2) +  pow(ptr1->Gender - ptr2->Gender, 2) + pow(ptr1->MaritalStatus - ptr2->MaritalStatus, 2) 
                          + pow(ptr1->Race - ptr2->Race, 2) +  pow(ptr1->BirthPlace- ptr2->BirthPlace, 2) + pow(ptr1->Language - ptr2->Language, 2) 
                          + pow(ptr1->Occupation - ptr2->Occupation, 2) + pow(ptr1->Income - ptr2->Income, 2) , 0.5); 

      if ( ptr1->ULAB[i] > Maximum){Maximum = ptr1->ULAB[i];}
      ptr2 = ptr2->next; // move ptr2
      i++;
	}
    
    ptr1 = ptr1->next; // move ptr1
}


/*                   CONVERTING ULAB TO NLAB                                        */


printf("%f\n", Maximum ); 

ptr1 = Header.next;

while(ptr1 != NULL)
{
	printf("\n");	
	for (i = 0; i< Users; i++)
	{
		ptr1->ULAB[i] = 1 - (ptr1->ULAB[i] / Maximum);
		printf("%.2f\n", ptr1->ULAB[i] ); 
		
	}

	 
	ptr1 = ptr1->next;
}


printf("\n");
/*                        QUERYY 333333333                      */ 

ptr1 = Header.next;

for(i=1; i < QueryNode; i++)
{
  ptr1 = ptr1->next;         // move ptr1 to  query node
}

j=0;
for(i = 0; i < Users; i++)
{
  if( (ptr1->ULAB[i] > Thresh1) && ((i+1) != QueryNode) )
  {
  Query3Array1[j] = i + 1;
  j++;  
  }
}

quickSort(Query3Array1, 0, j-1);
Count31 = j;


for(i = 0; i <j; i++)
{
  printf("%d ", Query3Array1[i]);
} 

printf("\n");


j=0;
for(i = 0; i < Users; i++)
{
  if( (ptr1->ULAB[i] > Thresh2) && ((i+1) != QueryNode) )
  {
  Query3Array2[j] = i + 1;
  j++;  
  }
}

quickSort(Query3Array2, 0, j-1);
Count32 = j;

for(i = 0; i <j; i++)
{
  printf("%d ", Query3Array2[i]);
} 

printf("\n");

/*---------------------- QUERYY 4444444444444444444444    */

/*---------------------- QUERYY 5555555555555555555555    */

/*---------------------- QUERYY 6666666666666666666666    */


fclose(fp);
return 0;

}


/*                                                              */
/*                     SORTING ALGORITHM                        */
void quickSort( int a[], int lb, int ub)
{

  int sTack[ub - lb  + 1];   // initializing sTack
  int index = 0;
  int i;

  sTack[0] = lb;               // push lowerbound
  sTack[++index] = ub;        // push upperbound

  while ( index >= 0) 
  {
    ub = sTack[ index--];
    lb = sTack[ index--];

    i = partition( a, lb, ub);

    if ( (i -1) > lb)        // left
    {
      sTack[ ++index] = lb;
      sTack[ ++index] = i -1;
    }

    if ( ( i + 1) < ub )     // right
    {
       sTack[ ++index] = i + 1;
      sTack[ ++index] = ub;
    }


  }
}


int partition( int a[], int Left, int Right) 
{
   int pivot, temp, index;
  // pivot = a[lb];

   index =  Left + (Right - Left)/2 ;  // Middle pivot
   pivot = a[index];

    
   while( Left <= Right)
   {
      while( (a[Left] <= pivot)  && (Left <= Right)){Left++;} // move left
      while( (a[Right] > pivot) ) {Right--;}             // move right
   
    
      if ( Right < Left){break;}

      if ( Right == index) { index = Left;}
    
    
      temp = a[Left];              // exchange right and left
      a[Left] = a[Right];
      a[Right] = temp; 
      
    }

   //temp = pivot;         // exchange pivot w/ right
   a[ index] = a[Right]; 
   a[Right] = pivot;
   return Right;      // Right is index of positioned pivot
}





