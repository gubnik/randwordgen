CC=g++

.PHONY: all rwgen

all: rwgen
	$(CC) bin/rwordgen main.cpp

rwgen: src/rwordgen.cpp header/rwordgen.hpp
	$(CC) -o bin/rwordgen -c src/rwordgen.cpp

