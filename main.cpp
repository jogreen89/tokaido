// main.cpp
//
// Simple main for testing C++ classes.
// 2016 (c) zubernetes
#include "bst.h"

int main(int argc, char **argv) {
    Node m = {.key = 10, .left = NULL, .right = NULL, .parent = NULL };
    Node n = {.key = 5, .left = NULL, .right = NULL, .parent = NULL };
    Node o = {.key = 15, .left = NULL, .right = NULL, .parent = NULL };

    BST* b = new BST();
    b->insertNode(&m);
    
    printf("here is my key : %d\n", b->getRoot()->key);
    printf("size of the bst : %d\n", b->getSize());

    b->insertNode(&n);
    
    printf("here is my key : %d\n", b->getRoot()->key);
    printf("size of the bst : %d\n", b->getSize());

	return 0;
}
