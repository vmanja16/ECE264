#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer09.h"

char * * explode(const char * str, const char * delims, int * arrLen)


{

    const char *s = str;
    int N = 0;
    char buffer[9000]; // temp[100];
    memcpy(buffer, s, (strlen(str) +1) * sizeof(char));
    s = buffer;

    while (*s != '\0')  // while pointer is not on null terminator
        {
        if ( strchr(delims, *s) != NULL) // If *s is in delims
            {
            N++;
            printf("%c\n", *s);
            }
        s++;
        } 

 
     

    *arrLen = N + 1; // Number of strings is delimiters + 1
    
    char * * strArr = malloc ( sizeof(char * ) * (*arrLen) );    

    s = &str[0];
    
    int I = 0, J = 0, H = 0;
    int Previous = 0;
    int  Current = 0;
    int Counter = 0;
    
for( Counter = 0; Counter < *arrLen; Counter++)
    {
        while( (strchr(delims, *s) == NULL)  && (*s != '\0' ))
            {
            Current++;           //  Location of newest delim
            s++;
            }        

        I = Counter;
        strArr[I] = malloc ( sizeof(char) * (Current-Previous + 1) ); //maloc for string

        J = 0;
        for (H=Previous; H < Current; H++)  
            {
            strArr[I][J] = str[H];
            J++;
            }
    
        strArr[I][J] = ('\0'); // Adding null character
          
        printf(" strArr[%d] is %s\n", I, strArr[I] );
    ++Current;
    Previous = Current;
    s++;
    }


    

    return (strArr);
}
 
/*
typedef struct bnode {
  char * name;
  char * stars;
  char * address;

  struct bnode * left;
  struct bnode * right;
} BusinessNode;
*/

BusinessNode *
create_node(char * stars, char * name, char * address)
{
	BusinessNode * NewNode = malloc(sizeof(BusinessNode));
	NewNode->name = name;
	NewNode->stars = stars;
	NewNode->address = address;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}


/* Insert a node into a BST. Primarily used in load_tree_from_file(). Return a
 * pointer to the root of the BST.
 */
BusinessNode *
tree_insert(BusinessNode * node, BusinessNode * root)
{
    BusinessNode * pointer1 = root, * pointer2 = NULL;

    if (strcmp(node->name, pointer1->name) <= 0)
    {
        while ( (strcmp(node->name, pointer1->name) <= 0) && (pointer1->left != NULL) )
        {
            pointer2 = pointer1;
            pointer1 = pointer1->left;
        }
        if (pointer1->left == NULL) // if at bottom of tree
        {
            pointer1->left = node;
            node->left = NULL;
            node->right = NULL;
        }
        else
        {
            pointer2->left = node;
            node->left = pointer1;
            node->right = NULL;
        }
    }

    if (strcmp(node->name, pointer1->name) > 0)
    {
        while ( (strcmp(node->name, pointer1->name) > 0) && (pointer1->right != NULL) )
        {
            pointer2 = pointer1;
            pointer1 = pointer1->right;
        }
        if (pointer1->right == NULL) // if at bottom of tree
        {
            pointer1->right = node;
            node->left = NULL;
            node->right = NULL;
        }
        else
        {
            pointer2->right = node;
            node->right = pointer1;
            node->left = NULL;
        }

    }
return root;
}

/* Parse a .tsv file line by line, create a BusinessNode for each entry, and
 * enter that node into a new BST. Return a pointer to the root of the BST.
 *
 * The explode(...) function from PA03 may be useful for breaking up a lines 
 * into seperate fields. 
 */
BusinessNode *
load_tree_from_file(char * filename)
{
	FILE * fp = fopen(filename, "r");
    if ( fp == NULL){ return NULL;}
	char buffer[9000];
	 char ** Line = NULL;

	while(feof(fp) ==0)
	{
		fgets(buffer, 900,fp);
		

	}


	fclose(fp);
	return NULL;
}


/* Search a BusinessNode BST for the node with the name 'name'. Returns
 * pointer to the node with a match.
 *
 * If there is no match, return NULL.
 */
BusinessNode *
tree_search_name(char * name, BusinessNode * root)

{
return root;
}/* Print out a single node: name, address, and stars
 * The format can be similar to this:
 *
 * Country Cafe
 * ============
 * Stars:
 *    3.5
 * Address:
 *    1030 Emerald Ter, Sun Prairie, WI 53590
 *
 * This function is not graded, but it could come in very handful while
 * debugging this assignment.
 */
void
print_node(BusinessNode * node)

{
printf("%s\n", node->name );
printf("================\n");
printf("Stars:\n%s\n", node->stars);
printf("Address:\n%s\n", node->address);

}
/* Print the entire tree, starting from the root. Like the print_node(...)
 * function, this is not graded.
 */
void
print_tree(BusinessNode * tree)

{

}
/* Deallocate all of the memory used by a BusinessNode BST, without memory
 * leaks.
 */
void destroy_tree(BusinessNode * root)
{

	BusinessNode * Node = root;
	if (Node == NULL)
	{
		return;
	}

	destroy_tree(Node->left);
	destroy_tree(Node->right);
	free(Node->stars);
	free(Node->address);
	free(Node->name);
	free(Node);
	Node = NULL;

	return;
}

