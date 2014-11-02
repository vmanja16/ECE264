#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer08.h"



List * List_createNode(const char * str)

{
	List * NewNode = malloc(sizeof(List));
	NewNode->str = strdup(str);
	NewNode->next = NULL;
	return NewNode;
}


void List_destroy(List * list)
{
	if (list == NULL) { return;}   // cant work with a NULL pointer
	List* Next = list->next;            // get a pointer to next node before freeing current node
	while(Next != NULL) { 
		free(list->str);
		free(list); 
		list = Next;
		Next = list->next;  }
	free(list->str);
	free(list);
}


int List_length(List * list)
{
	if(list == NULL){return 0;}
	int Length = 1;
	List* tail = list;
    while (tail->next != NULL) {
    tail = tail->next;
    Length++;   } // finds tail 
    
	return Length;
}


List * List_merge(List * lhs, 
		  List * rhs, 
		  int (*compar)(const char *, const char*))

{
	List  MergedList;
	MergedList.next = NULL; // Creating Empty List (1)
	List * Temp = &MergedList; // Initializing Temp pointer

	
	if (lhs == NULL) // checks to if leftside is ended
		{
			MergedList.next = rhs;
		}	

		if (rhs == NULL) // checks to if rightside is ended
		{
			MergedList.next = lhs;
		}	

	while ( (lhs != NULL) && (rhs != NULL) )
	{
		if ( compar(lhs->str, rhs->str) <= 0) // if left side small
		{
			Temp->next = lhs;
			lhs = lhs->next;
		}

		else 
		{
			Temp->next = rhs;//if right side small
			rhs = rhs->next;
		}
 		Temp = Temp->next; // Move Temp pointer forward
	}
	
	if (lhs == NULL) // checks to if leftside is ended
		{
			Temp->next = rhs;
		}	

		if (rhs == NULL) // checks to if rightside is ended
		{
			Temp->next = lhs;
		}	
	return MergedList.next;
}

/** 
 * 
 * The brief instructions are as follows:
 *
 * (1) Base case: 
 * Lists of length 0 or 1 are already (defacto) sorted. In this case, return
 * 'list'.
 *
 * (2) Recursive case: 
 * (2.a) Split the linked-list into two approx. equal sized lists.
 * (2.b) Call List_sort(...) on each of these smaller lists.
 * (2.c) Call List_merge(...) to merge the now sorted smaller lists into a 
 *       single larger sorted list, which you return.
 *
 * Well-written code should be 20-30 lines long, including comments and spacing.
 * If your code is longer than this, then you may save time by rethinking your
 * approach.
 */
List * List_sort(List * list, int (*compar)(const char *, const char*))

{
	if ( List_length(list) < 2) {return list;}//basecase
	
	int Count = 1, Length = List_length(list);
    List *tail = list, *Head = list;

     for (Count = 1; Count < (Length/2); Count++) 
    	{tail = tail->next; } 

    List * head = tail->next;
    tail->next = NULL; 

    Head = List_sort(Head, compar);
    head = List_sort(head, compar);
	return List_merge(Head, head, compar);
}

