/* Thomas Burch
   CS101
   Pa 4
   5/27/15
*/
   
/* minPQ.h (what is the purpose of this file?)
*/
#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* Access functions (what are the preconditions?)
*	pre: 	MinPQNode is a created struct
			paramaters are correctly implemented/ called
			isEmptyPQ: MinPQ pq is exisits
			getMin: there is a min to get
			getStatus: int id, is unseen, fringe, intree	
			getParent: there is always a parent, and the previous node exisits
			getPriority: MinPQ pq exisits
*/

/** isEmpty
*/
int isEmptyPQ(MinPQ pq);

/** getMin
*	
*/
int getMin(MinPQ pq);

/** getStatus
*/
int getStatus(MinPQ pq, int id);

/** getParent
*/
int getParent(MinPQ pq, int id);

/** getPriority
*/
double getPriority(MinPQ pq, int id);

/* Manipulation procedures (what are the preconditions and postconditions?)
		pre: 	delMin:  there is a MinPQ pq, exists
				insertPQ:	all the parameters exist
				decreaseKey: all the parameters exisit

		post:	delMin: will delate min of PQ
				insertPQ: will insert value into PQ
				descreaseKey: will decreasekey of PQ
*/

/** delMin
*/
void delMin(MinPQ pq);

/** insertPQ
*/
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey
*/
void decreaseKey(MinPQ pq, int id, double priority, int par);

/* Constructors (what are the preconditions and postconditions?)
	pre: 	intialize and allocate int arrays of status, priority, parent
			Original Graph or EdgeList exists creating adjInfo
	post: 	all the int arrays allocated are filled with the correct data after Prim or Dikstras is ran on the adjInfo.
*/


/**
*/
MinPQ createPQ(int n, int* status, double* priority, int* parent);

#endif




