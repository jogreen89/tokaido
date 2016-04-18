// bankers.cpp
// 
// A C++ implementation of the Bankers
// Algorithm for a simulation of 
// process-resource allocation.
#include "reader.h"
#include "operations.h"

int main(int argc, char **argv) {
    char *filename;
    // Check for input FILE path
    if (argc < 2) {
        printf("Usage: bankers input_file\n");
        return 0;
    }
    
    // Handle File I/O
    filename = argv[1];
    readInFile(filename);
    return 0;
}
