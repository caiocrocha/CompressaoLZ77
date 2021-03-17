CC=g++

CC_FLAGS=-W -Wall -pedantic -std=c++11

build: main

main: src/* main.cpp
	$(CC) $(CC_FLAGS) -o $@ $^
