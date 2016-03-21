// main.cpp
//
// Simple main for testing C++ classes.
// 2016 (c) zubernetes
#include "bst.h"

int main(int argc, char **argv) {
    Node m = {.key = 11, .left = NULL, .right = NULL, .parent = NULL };
    Node n = {.key = 10, .left = NULL, .right = NULL, .parent = NULL };
    Node o = {.key = 15, .left = NULL, .right = NULL, .parent = NULL };
    Node p = {.key = 12, .left = NULL, .right = NULL, .parent = NULL };
    Node q = {.key = 27, .left = NULL, .right = NULL, .parent = NULL };
    Node r = {.key = 25, .left = NULL, .right = NULL, .parent = NULL };

    m.left   = &n;
    m.right  = &o;
    
    o.left   = &p;
    o.right  = &q;
    o.parent = &m;

    q.left   = &r;
    q.parent = &o; 
    
    BST *b = new BST();
    b->traverseinorder();
    
	return 0;
}
