# Define required macros here
SHELL = /bin/sh

OBJS =  main.cpp complex.cpp 
CFLAG = -Wall -g
CC = g++
INCLUDE =
LIBS = -lm

complex:	${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<