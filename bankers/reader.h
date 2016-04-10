#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
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
    FILE *open_file;
    int n = 0, m = 0, i = 0, j = 0, k = 0;

    open_file = fopen(c, "r");
    
    while (fscanf(open_file, "%s", buffer) != EOF) {
        // if char == 'n'
        if (strcmp(buffer, "n") == 0) {  
            fscanf(open_file, "%s", buffer);
            printf("n\n%s\n", buffer);
            n = atoi(buffer);              // the number of processes
        }

        // if char == 'm'
        if (strcmp(buffer, "m") == 0) {
            fscanf(open_file, "%s", buffer);
            printf("m\n%s\n", buffer);
            m = atoi(buffer);              // the number of resources
        }
        
        // if char == 'Available'
        if (strcmp(buffer, "Available") == 0) {
            printf("%s\n", buffer);
            // Get resources [row][col] -- [n][m]
            // and create available[row][col]
            int *available = new int[m];
            for (i = 0; i < m; i++) {
                fscanf(open_file, "%s", buffer);
                printf("%s ", buffer);
                k = atoi(buffer);
                available[i] = k;
            }
            i = 0;
            printf("\n");
        }
        
        // if char == 'Allocation'
        if (strcmp(buffer, "Allocation") == 0) {
            printf("%s\n", buffer);
            // Get resources [row][col] -- [n][m]
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    fscanf(open_file, "%s", buffer);
                    printf("%s ", buffer);
                }
                printf("\n");
            }
            i = 0, j = 0;
        }
        
        // if char == 'Max'
        if (strcmp(buffer, "Max") == 0) {
            printf("%s\n", buffer);        
            // Get resources [row][col] -- [n][m]
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    fscanf(open_file, "%s", buffer);
                    printf("%s ", buffer);
                }
                printf("\n");
            }
            i = 0, j = 0;
        }
    }
}

#endif
