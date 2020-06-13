/* Thomas Burch
   CS101
   Pa 3
   5/27/15
*/

#include <stdlib.h>
#include "intList.h"	

	struct IntListNode{
		int element;
		IntList next;
	};

	typedef struct IntListNode* IntList;	// struct IntListNode point to IntList
	
	const IntList intNil = NULL;			// intNil is null, empty list

	 int intFirst(IntList oldL){			// top of list
	 	return oldL->element;
	 }
	 IntList intRest(IntList oldL){			
	 	return oldL->next;
	 }

	IntList intCons(int newE, IntList oldL){
		IntList newList = calloc(1, sizeof(struct IntListNode)); 	// decrement down the list															// 1 is used because it only holds one int at a time its called
		newList->element = newE;
		newList->next = oldL;
		return newList;
	}




