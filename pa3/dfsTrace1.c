/* Thomas Burch tburch1 1314305
   CS101
   Pa 3
   5/27/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include "dfsTrace1.h"

#define WHITE 0
#define GREY 1
#define BLACK 2

static 	int Time = 0;
static	int stack = 0;
static	int w = 0;
static int v = 1;

int dfs(IntList* adjVertices, int* color, int v, int* discoverTime1, int* finishTime1, int* parent1, int* finishStk1){
	IntList remAdj;
	color[v] = GREY;
	int wAns;
	int ans = 0;


	remAdj = adjVertices[v];

	while(remAdj != NULL){
		w = intFirst(remAdj);

	if(color[w] == WHITE){

		Time++;
		discoverTime1[w] = Time;	//storing discovery times of original graphx

		parent1[w] = v;				// storing parent of original graph

		wAns = dfs(adjVertices, color, w, discoverTime1, finishTime1, parent1, finishStk1);
	}

	if(color[w] != WHITE){
		remAdj = intRest(remAdj);

	}
	}

	color[v] = BLACK;

	Time++;
	finishTime1[v] = Time;	//storing finishTimes of original graph

	stack++;
	finishStk1[stack] = v;	//storing finishingStack of original graph

	return ans;
	}

int dfsSweep(IntList* adjVertices, int n, int* discoverTime1, int* finishTime1, int* parent1, int* finishStk1){
	int* color = calloc(n+1, sizeof(int));
	int i;
	int vAns;
	int ans = 0;

	for(i=1; i<=n; i++){		//initializing int arrays
		color[i] = WHITE;
		parent1[i] = -1;
		discoverTime1[i] = 0;
		finishTime1[i] = 0;
		finishStk1[i] = 0;	
	}

	for(v=1; v<=n; v++){
		if(color[v] == WHITE){
			Time++;
			discoverTime1[v] = Time;	//storing discovery time original graph
			vAns = dfs(adjVertices, color, v, discoverTime1, finishTime1, parent1, finishStk1);
		}
	}
	return ans;
}