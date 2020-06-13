/* Thomas Burch tburch1 1314305
   CS101
   Pa 3
   5/27/15
*/

/* intList.h
 * (what is the purpose of this file?)
 	To hold the declarations of the intList.c.
 */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * (what are the preconditions?) 
 	intFirst precondition: IntList does not equal intNil
 	intRest precondition: IntList does not equal intNil, both holding values
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 */
IntList intRest(IntList oldL);

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
IntList intCons(int newE, IntList oldL);

#endif