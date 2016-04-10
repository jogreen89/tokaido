#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "simulation.h"

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
    FILE *open_file;
    char buffer[BUFFER_SIZE];
    int n = 0, m = 0, i = 0, j = 0, k = 0;
    Simulation s;

    open_file = fopen(c, "r");
    
    while (fscanf(open_file, "%s", buffer) != EOF) {

        // reader finds 'n', the number of processes 
        if (strcmp(buffer, "n") == 0) {  
            fscanf(open_file, "%s", buffer);
            n = atoi(buffer);                   // the number of processes
            s.n = n;
            printf("n\n%d\n", s.n);
        }

        // reader finds 'm', the number of resources 
        if (strcmp(buffer, "m") == 0) {
            fscanf(open_file, "%s", buffer);
            m = atoi(buffer);                   // the number of resources
            s.m = m;
            printf("m\n%d\n", s.m);
            printSimulation(&s);
        }

        // reader finds 'Available', the Available resources
        if (strcmp(buffer, "Available") == 0) {
            printf("%s\n", buffer);
            // Get resources [row][col] -- [n][m]
            for (i = 0; i < m; i++) {
                fscanf(open_file, "%s", buffer);
                k = atoi(buffer);
                printf("%d ", k); 
            }
            i = 0, k = 0;
            printf("\n");
        }
        
        // reader finds 'Allocation', the Allocation matrix[n][m] 
        if (strcmp(buffer, "Allocation") == 0) {
            printf("%s\n", buffer);
            // Get resources [row][col] -- [n][m]
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    fscanf(open_file, "%s", buffer);
                    k = atoi(buffer);
                    printf("%d ", k);
                }
                printf("\n");
            }
            i = 0, j = 0, k = 0;
        }
        
        // reader finds 'Max', the Max matrix[n][m] 
        if (strcmp(buffer, "Max") == 0) {
            printf("%s\n", buffer);        
            // Get resources [row][col] -- [n][m]
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    fscanf(open_file, "%s", buffer);
                    k = atoi(buffer);
                    printf("%d ", k);
                }
                printf("\n");
            }
            i = 0, j = 0, k = 0;
        }
    }
}

#endif
