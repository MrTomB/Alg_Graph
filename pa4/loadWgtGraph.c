/* Thomas Burch
   CS101
   Pa 4
   5/27/15
*/
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadWgtGraph.h"
#include "edgeList.h"


int parseN(FILE* infile){
		int n; 												
		int scanfRetN;										
		char findN[1024];

		while((fgets(findN, 1024 , infile)) != NULL){		
	 	scanfRetN =	sscanf(findN, "%d", &n);
			if(scanfRetN != 1){								// check for scanfRetN for EOF or input error not being 1 input
					printf("Bad line.\n");						// print error message if wrong input in .text or stdin
					return 1;
				}else{
	                break;
	 	        }
	 	}
	 	return n;   														// print the number of vertices "n ="
}

EdgeList* initEdges(int n){
		EdgeList* graph = calloc(n+1, sizeof(EdgeList));
		int i;
		for(i=0; i<n+1; i++){
			graph[i] = edgeNil;
		}
		return graph;
}

int loadEdges(EdgeList* adjInfo, char task, int n, FILE* infile){
	 	    int m = 0;
	 		int x;
	 		int y;
	 		double z;
	 		EdgeInfo adjInfo1;
	 		char findM[1024];
	 		int scanfRetM;

	 		//char* vertices;
	 		//vertices = fgets(findM, 1024 , infile);

        while((fgets(findM, 1024 , infile)) != NULL){

	 			scanfRetM =	sscanf(findM, "%d %d %lf", &x, &y, &z);
	 			if(scanfRetM != 3){
	 				printf("Bad edge.\n");						// print error message if wrong input in .text or stdin
					return 1;
				}

					adjInfo1.to = y;
					adjInfo1.wgt = z;
					adjInfo[x] = edgeCons(adjInfo1, adjInfo[x]);	// calls the intCons from intList.c
					
				if(task == 'P'){
					adjInfo1.to = x;
					adjInfo[y] = edgeCons(adjInfo1, adjInfo[y]);
				}
				m++;
		}
				return m;
	}




