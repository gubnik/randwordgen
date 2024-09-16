CC=g++

.PHONY: all rwgen

all: rwgen
	$(CC) bin/rwordgen.o main.cpp

rwgen: src/rwordgen.cpp header/rwordgen.hpp
	$(CC) -o bin/rwordgen.o -c src/rwordgen.cpp

