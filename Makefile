#Terrible makefile
CC=gcc
CXX=g++
RM=rm -f
INC=-I./include
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

OUTPUT=build/tetris
DELOUTPUT=build/tetris
SRCS=src/*.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: 
	$(CXX) -Wall $(SRCS) $(INC) -o$(OUTPUT) -lSDL2main -lSDL2
compile:
	$(CXX) -Wall $(SRCS) $(INC) -o$(OUTPUT) -lSDL2main -lSDL2
run:
	$(CXX) $(SRCS) $(INC) -o$(OUTPUT) -lSDL2main -lSDL2
	./build/tetris
clean: 
	rm $(DELOUTPUT)
