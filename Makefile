CC=g++
FLAGS=-std=c++11 -Wall
INCLUDES=-I include/
LIB_DIR=-L lib/mac/
LIBS=-l glfw.3 -l glew
SRC=src/*.cpp src/glad.c
OUT=debug/tic_tac_toe

.PHONY: build clean

build:
	${CC} -v ${FLAGS} ${SRC} ${INCLUDES} ${LIB_DIR} -framework OpenGL ${LIBS} -o ${OUT}

clean:
	rm -f ${PROG}
