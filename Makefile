CC=g++
STD=c++11
INCLUDES=-I include
SRC=src
PROG=tic_tac_toe

.PHONY: build clean

build:
	${CC} -std=${STD} ${SRC}/* ${INCLUDES} -o ${PROG}

clean:
	rm -f ${PROG}
