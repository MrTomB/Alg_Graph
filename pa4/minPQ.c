/* Thomas Burch
   CS101
   Pa 4
   5/27/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "minPQ.h"

struct MinPQNode{
	int* status;
	int* parent;
	int numPQ;
	int minVertex;
	double oo;
	double* fringeWgt;
	int numVertices;

};

//boolean is Empty(MinPq pq)
int isEmptyPQ(MinPQ pq){
	if(pq->numPQ == 0){
		return 1;
	}
		return 0;
}

// Return fringe vertex with min wgt.
// Return -1 if no fringe vertex remains.

//This subroutine does most of the work!

int getStatus(MinPQ pq, int id){
	return pq->status[id];
}

int getParent(MinPQ pq, int id){
	return pq->parent[id];
}

double getPriority(MinPQ pq, int id){
	return pq->fringeWgt[id];
}

int getMin(MinPQ pq){
	if(pq->minVertex == -1){
	int v;
	double minWgt;
	minWgt = pq->oo;
	for(v=1; v<= pq->numVertices; v++){
		if(getStatus(pq, v) == FRINGE){ //
			if(getPriority(pq, v) < minWgt){ //
				pq->minVertex = v;
				minWgt = getPriority(pq, v); //
		//Continue loop
			}
		}
	}
	}
	return pq->minVertex;
}

// Delete fringe vertex with min wgt from pq.
void delMin(MinPQ pq){
	int oldMin;
	oldMin = getMin(pq);
	pq->status[oldMin] = INTREE;
	pq->minVertex = -1;
	pq->numPQ--;
}

// Record newPar, new W as parent, priority of v and make status[v] = fringe

void insertPQ(MinPQ pq, int id, double priority, int par){
	pq->parent[id] = par;
	pq->fringeWgt[id] = priority;
	pq->status[id] = FRINGE;
	pq->minVertex = -1;
	pq->numPQ+=1;
}

// Record newPar, newW as parent, priority of v.
void decreaseKey(MinPQ pq, int id, double priority, int par){
	pq->parent[id] = par;
	pq->fringeWgt[id] = priority;
	pq->minVertex = -1;
}

// Construct pq on n vertices, all "unseen"
MinPQ createPQ(int n, int* status, double* priority, int* parent){
	MinPQ pq = calloc(n+1, sizeof(MinPQ));
	pq->parent = parent;
	pq->fringeWgt = priority;
	pq->status = status;
	// Initialize status[1],...., status[n] to unseen.
	int i;
	for(i = 1; i<=n; i++){
		pq->status[i] = UNSEEN;
	}

	pq->numVertices = n;
	pq->numPQ = 0;
	pq->minVertex = -1;
	pq->oo = HUGE_VAL;
	return pq;
}

