#include "reader.h"
#include "operations.h"

int main(int argc, char **argv) {
    char *filename;
    if (argc < 2) {
        printf("Usage: bankers input_file\n");
        return 0;
    }

    filename = argv[1];

    printRead(); 
    printOP();
    printInFile(filename);
    readInFile(filename);
}
