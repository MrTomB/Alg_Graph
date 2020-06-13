/* Thomas Burch tburch1 1314305
   CS101
   Pa 3
   5/27/15
*/

#include "intList.h"

/*pre & post conditions:
	pre: 	intialize and allocate int arrays of discoverTime1, finishTime1, parent1, finishStk1
			Original Graph or IntList exists creating adjVertices
	post: 	returning int ans = 0, not changed due to int return needed
			all the int arrays allocated are filled with the correct data after dfs is ran on the Original Graph.
			finishStk1 is created for the Transpose Graph.
*/

int dfs(IntList* adjVertices, int* color, int v, int* discoverTime1, int* finishTime1, int* parent1, int* finishStk1);

int dfsSweep(IntList* adjVertices, int n, int* discoverTime1, int* finishTime1, int* parent1, int* finishStk1);


