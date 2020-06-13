/* Thomas Burch tburch1 1314305
   CS101
   Pa 3
   5/27/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "dfsPhase2.h"

#define WHITE 1
#define GREY 2
#define BLACK 3

static int Time2 = 0;
static int v = 1;
static int w = 0;
static int leaders = 0;

int dfsT(IntList* adjVerticesT, int* colorT, int v, int* discoverTime2, int* finishTime2, int* parent2, int* dfstRoot2, int Leader){
	IntList remAdjT;
	int ans = 0;
	colorT[v] = GREY;		//changing visted nodes to grey
	int wAns;

	dfstRoot2[leaders] = Leader;	//storing the leaders of SCC

	remAdjT = adjVerticesT[v];

	while(remAdjT != NULL){
		w = intFirst(remAdjT);

	if(colorT[w] == WHITE){

		Time2++;
		discoverTime2[w] = Time2;	// storing dicovery time of transpose graph

		parent2[w] = v;				// storing parents of the nodes of transpose graph

		wAns = dfsT(adjVerticesT, colorT, w, discoverTime2, finishTime2, parent2, dfstRoot2, Leader);
	}
	if(colorT[w] != WHITE){
		remAdjT = intRest(remAdjT);

	}
	}
	

	colorT[v] = BLACK;		//changing visted nodes with no adjvertices to black

	Time2++;				
	finishTime2[v] = Time2;	//storing finishTimes of transpose graph

	return ans;
	}

int dfsSweepT(IntList* adjVerticesT, int n, int* finishStk1, int* discoverTime2, int* finishTime2, int* parent2, int* dfstRoot2){
	int ans = 0;	
	int i;
	int vAns;
	int* colorT = calloc(n+1, sizeof(int));

	for(i=1; i<=n; i++){		// initializing arrays
		colorT[i] = WHITE;
		parent2[i] = -1;
		discoverTime2[i] = 0;
		finishTime2[i] = 0;
		dfstRoot2[i] = 0;

	}

	for(v=n; v>=1; v--){
		if(colorT[finishStk1[v]] == WHITE){

			Time2++;
			discoverTime2[finishStk1[v]] = Time2;	//storing discovery times of transpose graph

			leaders++;

			vAns = dfsT(adjVerticesT, colorT, finishStk1[v], discoverTime2, finishTime2, parent2, dfstRoot2, finishStk1[v]);
		}
	}
	return ans;
}