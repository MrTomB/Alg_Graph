/* Thomas Burch
   CS101
   Pa 4
   5/27/15
*/
/* edgeList.h
 * (what is the purpose of this file?)
 */

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode* EdgeList;

typedef struct EdgeInfoStruct{
    int to;
    double wgt;
    }EdgeInfo;


/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions
 * (what are the preconditions?)

 	edgeFirst precondition: edgeList does not equal edgeNil
 	edgeRest precondition: edgeList does not equal edgeNil, both holding values
 */

/** first
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
EdgeList edgeRest(EdgeList oldL);

/* Constructors
 * (what are the preconditions and postconditions?)
  	precondition: none
	postcondition:  1) x refers to a newly created object;
					2) x is not equal to intnil
					3) first(x) = newElement;
					4) rest(x) = oldList;
 */

/** cons
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif