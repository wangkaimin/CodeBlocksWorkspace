/*--- llapp.c ----------------------------- Listing 2-4b --------
 *  Application-specific functions for linked-list examples.
 *  Replace these routines with your own.
 *-------------------------------------------------------------*/

#include <stdlib.h>         /* for free() */
#include <string.h>         /* for strcmp() and strdup() */
#include <string.h>
#include "llgen.h"
#include "llapp.h"

/* data is a pointer to a ElementType */
void * CreateData1 ( void * data )
{
    struct NodeData1 * new_data;

    /*--- allocate our data structure ---*/
    if ((new_data = (pND1)malloc ( sizeof ( struct NodeData1 ))) == NULL)
        return ( NULL );

    /*--- move the values into the data structure ---*/
    new_data->u    =  1;
    new_data->element = (ElementType *)malloc(sizeof(ElementType));
    memcpy (new_data->element, (ElementType *) data ,4*sizeof(ElementType));

    if ( new_data->element == NULL )   /* error copying string */
    {
        free ( new_data );
        return ( NULL );
    }
    else
        return ( new_data ); /* return a complete structure */
}

int DeleteData1 ( void * data )
{
    /*
     * In this case, NodeData1 consists of: a pointer and an int.
     * The integer will be returned to memory when the node
     * is freed. However, the string must be freed manually.
     */
    free ( ((pND1) data)->element );
    return ( 1 );
}
/*---------------------------------------------------------------
 * This function determines what to do when inserting a node
 * into a list if an existing node with the same data is found
 * in the list. In this case, since we are counting words, if a
 * duplicate element is found, we simply increment the counter.
 *
 * Note this function should return one of the following values:
 *      0       an error occurred
 *      1       delete the duplicate node
 *      2       insert the duplicate node
 * Any other processing on the duplicate should be done in this
 * function.
 *-------------------------------------------------------------*/

int DuplicatedNode1 ( Link new_node, Link list_node )
{
    /* adding an occurrence to an existing element */

    pND1 pnd = (pND1)list_node->pdata;
    pnd->u += 1;
    return ( 1 );
}

int NodeDataCmp1 ( void *first, void *second )
{
    return ( memcmp ( ((pND1) first)->element,
                      ((pND1) second)->element,
                      (size_t)(4*sizeof(ElementType)) ));
}

/*=== Now the functions for the second linked list ===*/

void * CreateData2 ( void * data )
{
    struct NodeData2 * new_data;

    /*--- allocate the data structure ---*/
    if ((new_data = (pND2)malloc ( sizeof ( struct NodeData2 ))) == NULL)
        return ( NULL );

    /*--- move the values into the data structure ---*/
    new_data->element = (ElementType *)malloc(sizeof(ElementType));
    memcpy (new_data->element, (ElementType *) data ,4*sizeof(ElementType));

    if ( new_data->element == NULL )   /* error copying string */
    {
        free ( new_data );
        return ( NULL );
    }
    else
        return ( new_data );
}

int DeleteData2 ( void * data )
{
    /*
     * In this case, NodeData2 consists of a pointer.
     * The string must be freed manually.
     */

    free ( ((pND2) data)->element );
    return ( 1 );
}

/* this list inserts duplicated nodes */
int DuplicatedNode2 ( Link new_node, Link list_node )
{
    return ( 2 );
}

int NodeDataCmp2 ( void *first, void *second )
{
    return ( memcmp ( ((pND2) first)->element,
                      ((pND2) second)->element,
                      4*sizeof(ElementType)) );
}
