C     = gcc
CFLAGS = -g -Wall -O0

edgeList.o:	edgeList.c  edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

loadWgtGraph.o:	loadWgtGraph.c loadWgtGraph.h
	${CC}  -c  ${CFLAGS}  loadWgtGraph.c

minPQ.o:	minPQ.c minPQ.h
	${CC}  -c  ${CFLAGS}  minPQ.c

graph04.o:	graph04.c  edgeList.h
	${CC}  -c  ${CFLAGS}  graph04.c

graph04:	graph04.o  edgeList.o loadWgtGraph.o minPQ.o
	${CC}  -o  graph04  graph04.o edgeList.o loadWgtGraph.o minPQ.o