/* Thomas Burch
   CS101
   Pa 4
   5/27/15
*/

#include "edgeList.h"

/* 	preconditions: 	argc, and argv exist
					parseN is ran correctly, finding int n
					EdgeList struct is correctly created

	postconditions: parseN find value n, number of vertices
					initEdges intializes adjInfo
					loadEdges creates adjInfo depeneding on the task

*/

int parseN(FILE* infile);

EdgeList* initEdges(int n);

int loadEdges(EdgeList* adjInfo, char task, int n, FILE* infile);

