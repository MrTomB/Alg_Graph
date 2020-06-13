/* Thomas Burch
   CS101
   Pa 4
   5/27/15
*/

#include <stdlib.h>
#include "edgeList.h"	

	struct EdgeListNode{
		EdgeInfo element;
		EdgeList next;
	};

	const EdgeList edgeNil = NULL;			// intNil is null, empty list

	 EdgeInfo edgeFirst(EdgeList oldL){	    // top of list
	 	return oldL->element;
	 	
	 }

	 EdgeList edgeRest(EdgeList oldL){			
	 	return oldL->next;
	 }

	EdgeList edgeCons(EdgeInfo newE, EdgeList oldL){
		EdgeList newList = calloc(1, sizeof(struct EdgeListNode)); 	// decrement down the list
		newList->element = newE;	
		newList->next = oldL;
		return newList;
	}


