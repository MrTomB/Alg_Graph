/* Thomas Burch 1314305
   CS101
   Pa 1
   4/15/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "intList.h"

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

		if (argc != 2){											// argv[0] has file name, argv[1] is FILE pointer
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
			IntList* IntArray;									// IntList point to IntArray
			IntArray = calloc(n+1, sizeof(IntList));			// delcaring IntArray n+1 b/c 1-8

	 	while((fgets(findM, 1024 , infile)) != NULL){
	 			scanfRetM =	sscanf(findM, "%d %d", &x, &y);
				if(scanfRetM != 2){								// check for scanfRetM for EOF or input error not being 2 inputs
					printf("Bad edge.\n");						// print error message if wrong input in .text or stdin
					return 1;
				}else{
					IntArray[x] = intCons(y, IntArray[x]);		// calls the intCons from intList.c
					m++;

				}
        }

        printf("m = %d\n", m);									// print the number of edges "m ="

        printf("This is the Orginal Graph.\n");					
      	print(IntArray, n);										// printing orignalGraph

        IntList* T;
        T = calloc(n+1, sizeof(IntList));						// initalizing T IntLIst, allocating memory
        T = transposeGraph(IntArray, n); 						// transposing orignalGraph
        printf("This is the first transposeGraph.\n");
        print(T, n);

        IntList* T2;
        T2 = calloc(n+1, sizeof(IntList));						// initalizing T2 IntLIst, allocating memory
        T2 = transposeGraph(T, n);								// transposing tranposeGraph
        printf("This is the transpose of the transposeGraph.\n");
        print(T2, n);

        IntList* T3;
        T3 = calloc(n+1, sizeof(IntList));						// initalizing T3 IntLIst, allocating memory
        T3 = transposeGraph(T2, n);								// transposing the transpose of the transposeGraph
        printf("This is the third transposeGraph.\n");
        print(T3, n);
        
		return 0;
	}




