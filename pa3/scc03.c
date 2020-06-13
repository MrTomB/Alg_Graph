/* Thomas Burch tburch1 1314305
   CS101
   Pa 3
   5/27/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "intList.h"
#include "dfsTrace1.h"
#include "dfsPhase2.h"

    IntList* transposeGraph(IntList* origGraph, int n){

    	IntList* transposeGraph;
    	transposeGraph = calloc(n+1, sizeof(IntList));		// initalizing transposeGraph IntList, allocating memory

    	int c;
    	for(c=0; c<=n; c++){
    		transposeGraph[c] = intNil;						// NULL transposeGraph, no bad data in transposeGraph
    	}

    	int a;
  		int b;

    	for(a=1; a<=n; a++){
    		IntList L = origGraph[a];						// IntList L is a temp Intlist to not overright origGraph

			while(L != NULL){								
					b = intFirst(L);						// the actual transposing loop/ part
					transposeGraph[b] = intCons(a, transposeGraph[b]); 
					L = intRest(L);
			}
			}

		return transposeGraph;
    }

int hasCycleLen(IntList* origGraph, int n, int sofar, int v){
	if(sofar >= n){
		printf("Vertex [%d] MIGHT BE in cycle.\n", v);		// print vetix if cycle exisit
		return 1;
	}
	int f;
	int g;
	IntList L = origGraph[v];
	while(L != intNil){
		f = intFirst(L);
		g = hasCycleLen(origGraph, n, sofar+1, f);			// increment sofar by 1
		L = intRest(L);
	if(g == 1){
		return 1;
	}
	}
		return 0;
}

int hasCycle(IntList* origGraph, int n){
 	int i;
 	int j;
	for(i=1; i<=n; i++){
		j = hasCycleLen(origGraph, n, 0, i);				// calling hasCycleLen
		if(j == 1){
			return 1;										// return 1 if cycle
		}
	}
			return 0;										// return 0 if no cycle
	}

int print(IntList* IntArray, int n){
		int i;
		for(i=1; i<=n; i++){
			IntList Temp = IntArray[i];
			if(Temp == intNil){							// check if IntArray is empty
				printf("%d\t null\n", i);						// print null if true
			}else{
				printf("%d\t [%d", i, intFirst(Temp));	// print first edge, [second edge 
				while(intRest(Temp) != NULL){					// while there is more in the List
					Temp = intRest(Temp);						// decrement down the list
					printf(", %d", intFirst(Temp));				// print new current intFirst
				}
					printf("]\n");								// print closing braket
			}
        }

        int a;
        a = hasCycle(IntArray, n);
        if(a == 0){
        	printf("NO cycle.\n");
        }

        return 1;
}

	int main(int argc, char* argv[]){

		int n; 												
		int scanfRetN;										
		char findN[1024];

		if(argc != 2){											// argv[0] has file name, argv[1] is FILE pointer
			printf("Usage: graph input.data\n");
			return 1;
		}

		printf("Opened %s for input.\n", argv[1]);				//System.out.println("Opened " + infile + " for input.");
	 	FILE* infile;
	 	if(strcmp(argv[1],"-") == 0){							// check if "-" was inputed. asking for user input
	 		infile = stdin;
	 		}else{
	 	    infile = fopen (argv[1], "r");						// else open .text file
        }

	 	while((fgets(findN, 1024 , infile)) != NULL){		
	 		scanfRetN =	sscanf(findN, "%d", &n);
				if(scanfRetN != 1){								// check for scanfRetN for EOF or input error not being 1 input
					printf("Bad line.\n");						// print error message if wrong input in .text or stdin
					return 1;
				}else{
	                break;
	 	        }
	 	}

        printf("n = %d\n",n);									// print the number of vertices "n ="

	 	    int m = 0;
	 		int x, y;
	 		int scanfRetM;
			char findM[1024];
			IntList* adjVertices;									// IntList point to adjVertices
			adjVertices = calloc(n+1, sizeof(IntList));			// delcaring adjVertices n+1 b/c 1-8

	 	while((fgets(findM, 1024 , infile)) != NULL){
	 			scanfRetM =	sscanf(findM, "%d %d", &x, &y);
				if(scanfRetM != 2){								// check for scanfRetM for EOF or input error not being 2 inputs
					printf("Bad edge.\n");						// print error message if wrong input in .text or stdin
					return 1;
				}else{
						adjVertices[x] = intCons(y, adjVertices[x]);		// calls the intCons from intList.c
					m++;

				}
        }

        printf("m = %d\n", m);									//print m
        printf("This is the Original Graph.\n");				
        print(adjVertices, n);									//print original graph
        
        int* discoverTime1 = calloc(n+1, sizeof(int));			// allocating space for all the int arrays we will be using dfsTrace1
        int* finishTime1 = calloc(n+1, sizeof(int));
        int* parent1 = calloc(n+1, sizeof(int));
        int* finishStk1 = calloc(n+1, sizeof(int));

        int a;
        a = dfsSweep(adjVertices, n, discoverTime1, finishTime1, parent1, finishStk1);	//call first DFS using dfsTrace1

        	printf("Vertex\tdtime\tftime\tparent\t\n");			//printing of the table after the first dfs
        int d;
        for(d=1; d<=n; d++){
        	printf("%4d %8d %8d %8d\n", d, discoverTime1[d], finishTime1[d], parent1[d]);
        }
        	printf("finishStk1: ");								//printing of the finishingstk1 from top to bottom
        int f;
        for(f=n; f>=1; f--){
        	printf("%d ", finishStk1[f]);
        }

       	IntList* adjVerticesT;
        adjVerticesT = calloc(n+1, sizeof(IntList));						// initalizing T IntLIst, allocating memory
        adjVerticesT = transposeGraph(adjVertices, n);						// transposing orignalGraph
        
        printf("\n\nThis is the Transposed Graph.\n");
        print(adjVerticesT, n);

        int* discoverTime2 = calloc(n+1, sizeof(int));			//allocating space for all the int arrays we will be using in dfsPhase2
        int* finishTime2 = calloc(n+1, sizeof(int));
        int* parent2 = calloc(n+1, sizeof(int));
        int* dfstRoot2 = calloc(n+1, sizeof(int));

        int b;
        b = dfsSweepT(adjVerticesT, n, finishStk1, discoverTime2, finishTime2, parent2, dfstRoot2);

        	printf("Vertex\tdtime2\tftime2\tparent2\n");		//printing of the table after the transpose dfs
        int e;
        for(e=1; e<=n; e++){
        	printf("%4d %8d %8d %8d\n", e, discoverTime2[e], finishTime2[e], parent2[e]);
        }

        printf("dfstRoot2: ");									// printing of the leaders of the strongly connected components
        int h;
        for(h=1; h<=n; h++){
        	if(dfstRoot2[h] != 0){
        	printf("%d ", dfstRoot2[h]);
        	}
    	}
        printf("\n");

        return 0;
	}








