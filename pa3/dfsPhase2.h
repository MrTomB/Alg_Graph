/* Thomas Burch tburch1 1314305
   CS101
   Pa 3
   5/27/15
*/

#include "intList.h"

/*pre & post conditions:
	pre: 	intialize and allocate int arrays of discoverTime2, finishTime2, parent2, finishStk1, dfstRoot2
			Transpose Graph or IntList exists, preformed properly to create adjVerticesT
	post: 	returning int ans =0, not changed due to int return needed
			all the int arrays allocated are filled with the correct data after dfs is ran on the Transpose Graph.
			dfstRoot2 are filled with the leaders of each Strongly Component.
*/

int dfsT(IntList* adjVerticesT, int* colorT, int v, int* discoverTime2, int* finishTime2, int* parent2, int* dfstRoot2, int Leader);

int dfsSweepT(IntList* adjVerticesT, int n, int* finishStk1, int* discoverTime2, int* finishTime2, int* parent2, int* dfstRoot2);

