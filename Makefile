#Terrible makefile
CC=gcc
CXX=g++
RM=rm -f
INC=-I./include
MINC = -IC:\MinGW\include
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

OUTPUT=build/Tetris.exe
DELOUTPUT=build/Tetris.exe
SRCS=src/*.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: 
	$(CXX) $(SRCS) $(INC) -o$(OUTPUT) -lSDL2main -lSDL2
compile:
	$(CXX) $(SRCS) $(INC) -o$(OUTPUT) -lSDL2main -lSDL2
run:
	$(CXX) $(SRCS) $(INC) -o$(OUTPUT) -lSDL2main -lSDL2
	build/Tetris.exe
clean: 
	del $(DELOUTPUT)
