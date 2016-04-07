#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <cstring>

#define BUFFER_SIZE 100

void printRead(void);
void printInFile(char*);
void readInFile(char*);

void printRead(void) {
    printf("Hello, Reader.\n");
}

void printInFile(char *c) {
    printf("Hello, %s.\n", c);
}

void readInFile(char *c) {
    char buffer[BUFFER_SIZE];
    int line_number    = 1,
        n              = 0,            // the number of processes
        m              = 0,            // the number of resources
        process_number = 1;

    FILE *open_file;
    open_file = fopen(c, "r");
    
    while (fscanf(open_file, "%s", buffer) != EOF) {
        // if char == 'n'
        if (strcmp(buffer, "n") == 0) {  
            fscanf(open_file, "%s", buffer);
            printf("n is %s\n", buffer);
        }

        // if char == 'm'
        if (strcmp(buffer, "m") == 0) {
            fscanf(open_file, "%s", buffer);
            printf("m is %s\n", buffer);
        }
    }
}

#endif
