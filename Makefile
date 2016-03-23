# (c) 2016 zubernetes
CC = c++
CFLAGS = -g
SOURCES = main.cpp
EXECUTABLE = main 

all:
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(CFLAGS)
