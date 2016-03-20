// main.cpp
//
// Simple main for testing C++ classes.
// 2016 (c) zubernetes
#include "bst.h"

int main(int argc, char **argv) {
    Node* n = new Node(

    BST* b = new BST();
    b->insertNode(&n);
    
    printf("here is my root key : %d\n", b->getRoot()->key);
    
	return 0;
}
