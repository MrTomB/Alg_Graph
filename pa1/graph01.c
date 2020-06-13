/* Thomas Burch
   CS101
   Pa 1
   4/15/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "intList.h"

	int main(int argc, char* argv[]){

		int n; 												
		int scanfRetN;										
		char findN[1024];

		if (argc != 2){										// argv[0] has file name, argv[1] is FILE pointer
			printf("Usage: graph input.data\n");
			return 1;
		}

		printf("Opened %s for input.\n", argv[1]);			//System.out.println("Opened " + infile + " for input.");
	 	FILE * infile;
	 	if(strcmp(argv[1],"-") == 0){						// check if "-" was inputed. asking for user input
	 		infile = stdin;
	 	} else{
	 	    infile = fopen (argv[1], "r");					// else open .text file
        }

	 	while((fgets(findN, 1024 , infile)) != NULL){		
	 		scanfRetN =	sscanf(findN, "%d", &n);
				if(scanfRetN != 1){							// check for scanfRetN for EOF or input error not being 1 input
					printf("Bad line\n");					// print error message if wrong input in .text or stdin
					return 1;
				}else{
	                break;
	 	         }
	 	}

        printf("n = %d\n",n);								// print the number of vertices "n ="

	 	    int m = 0;
	 		int x, y;
	 		int scanfRetM;
			char findM[1024];
			IntList* IntArray;								// IntList point to IntArray
			IntArray = calloc(n+1, sizeof(IntList));		// delcaring IntArray n+1 b/c 1-8

	 	while((fgets(findM, 1024 , infile)) != NULL){
	 			scanfRetM =	sscanf(findM, "%d %d", &x, &y);
				if(scanfRetM != 2){								// check for scanfRetM for EOF or input error not being 2 inputs
					printf("Bad edge\n");						// print error message if wrong input in .text or stdin
					return 1;
				}else{
					IntArray[x] = intCons(y, IntArray[x]);		// calls the intCons from intList.c
					m++;

				}
        }
        printf("m = %d\n",m);									// print the number of edges "m ="


		int i;
		for(i=1; i<=n; i++){
			if(IntArray[i] == intNil){							// check if IntArray is empty
				printf("%d\t null\n", i);						// print null if true
			} else{
				printf("%d\t [%d", i, intFirst(IntArray[i]));	// print first edge, [second edge 
				while(intRest(IntArray[i]) != NULL){			// while there is more in the List
					IntArray[i] = intRest(IntArray[i]);			// decrement down the list
					printf(", %d", intFirst(IntArray[i]));		// print new current intFirst
				}
					printf("]\n");								// print closing braket
			}
        }
		return 0;	
	}

	










	
