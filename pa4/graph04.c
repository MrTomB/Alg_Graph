/* Thomas Burch tburch1 1314305
   CS101
   Pa 4
   5/27/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "minPQ.h"
#include "loadWgtGraph.h"
#include "edgeList.h"

static int task;
static int s;

void printOutput(int* status, double* fringeWgt, int* parent, double n){
    	printf("Vertex\tstatus\tpriority\tparent\n");

    	int a;
        for(a=1; a<=n; a++){
        	printf("%4d %6c %12lf %8d\n", a, status[a], fringeWgt[a], parent[a]);
        }
}

double calcPriority(EdgeInfo wInfo, int task, double myDist){
	double priority;
		if(task == 'P'){
			priority = wInfo.wgt;
		}
		if(task == 'D'){
			priority = myDist + wInfo.wgt;
		}
		return priority;
}
/* See if a better connection is found to any vertex in
	the list adjInfoOfV, and decreaseKey if so
	For a new connection, insert the vertex */

void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int v, int task){
	EdgeList remAdj;
	remAdj = adjInfoOfV;
	int w;
	EdgeInfo wInfo;
	double newWgt;
	double myDist = 0.0;
	
	myDist = getPriority(pq, v);

	while (remAdj != edgeNil){
		wInfo = edgeFirst(remAdj);
		w = wInfo.to;
		newWgt = calcPriority(wInfo, task, myDist);
		int stat;
		stat = getStatus(pq, w);

		if(stat == UNSEEN){
			insertPQ(pq, w, newWgt, v);
		}else if (stat == FRINGE){
			if(newWgt < getPriority(pq, w)){
				decreaseKey(pq, w, newWgt, v);
			}
		}
		remAdj = edgeRest(remAdj);
	} 								
} 										

void greedytree(EdgeList* adjInfo, int n, int s, int* parent, double* fringeWgt, int* status, int task){
	
	MinPQ pq = createPQ(n, status, fringeWgt, parent);

	insertPQ(pq, s, 0.0, -1);

	int v = 0; 
	while(isEmptyPQ(pq) == 0){
		v = getMin(pq);
		delMin(pq);
		updateFringe(pq, adjInfo[v], v, task);
	}
	return;
} // end greedytree

int main(int argc, char* argv[]){

		if(argc != 4){
			return 0;
		}

	 	s = atoi(argv[2]);

        if(strcmp(argv[1], "-P") == 0){							// check if "-" was inputed. asking for user input
	 		task = 'P';											// P is static
	 		printf("Prim MST starting at vertex %d\n", s);
	 	}
	 	
        if(strcmp(argv[1], "-D") == 0){							// check if "-" was inputed. asking for user input
	 		task = 'D';											// D is static
	 		printf("Dijkstra SSSP starting at vertex %d\n", s);
	 	}

	 	FILE* infile;
	 	if(strcmp(argv[3],"-") == 0){							// check if "-" was inputed. asking for user input
	 		infile = stdin;
	 		}else{
	 	    infile = fopen (argv[3], "r");						// else open .text file
        }

	 	printf("s = %d\n", s);

		int n;
		n = parseN(infile);
		printf("n = %d\n", n);

		EdgeList* adjInfo;

		adjInfo = initEdges(n);

		int* status = calloc(n+1, sizeof(int));				// allocating space for all the int arrays we will be using dfsTrace1
		int* parent = calloc(n+1, sizeof(int));
		double* fringeWgt = calloc(n+1, sizeof(double));

		int m;
		m = loadEdges(adjInfo, task, n, infile);
		printf("m = %d\n", m);

        greedytree(adjInfo, n, s, parent, fringeWgt, status, task);

        printOutput(status, fringeWgt, parent, n);

        return 0;
	}
