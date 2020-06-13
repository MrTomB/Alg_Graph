CC     = gcc
CFLAGS = -g -Wall -O0

intList.o:      intList.c  intList.h
        ${CC}  -c  ${CFLAGS}  intList.c

dfsTrace1.o:	dfsTrace1.c dfsTrace1.h
		${CC}  -c  ${CFLAGS}  dfsTrace1.c

dfsPhase2.o:    dfsPhase2.c dfsPhase2.h
		${CC}  -c  ${CFLAGS}  dfsPhase2.c

scc03.o:      scc03.c  intList.h
        ${CC}  -c  ${CFLAGS}  scc03.c

scc03:        scc03.o  intList.o
        ${CC}  -o  scc03  scc03.o intList.o