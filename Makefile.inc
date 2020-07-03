# Makefile.inc: definitions communes

PSE_DIR = ..
PSE_BIN = ${PSE_DIR}/bin
PSE_LIB = ${PSE_DIR}/lib
PSE_INCL_DIR = ${PSE_DIR}/include

CFLAGS = -g -I. -I${PSE_INCL_DIR} -Wall -std=c++0x
		
LDLIBS = -L${PSE_LIB} -ldeepG -lm -pthread -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

CC = g++
