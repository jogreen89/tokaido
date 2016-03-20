// main.cpp
//
// Simple main for testing C++ classes.
// 2016 (c) zubernetes
#include "bst.h"

int main(int argc, char **argv) {
    Node m = {.key = 4, .left = NULL, .right = NULL, .parent = NULL };

    BST* b = new BST();
    b->insertNode(&m);
    
    printf("here is my n key : %d\n", b->getRoot()->key);
    
	return 0;
}
