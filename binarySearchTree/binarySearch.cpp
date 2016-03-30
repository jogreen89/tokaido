// binarySearch.cpp
//
// A class-based binary-search tree.
// 2016 (c) zubernetes
#include "bst.h"
#include <iostream>

void testInorderTraversal(BST*); 
void testFindmax(BST*);
void testSuccessor(BST*, int);
void testDeletion(BST*, int);
void testInsertion(BST*, Node*); 
void testLoop(BST*);

int main(int argc, char** argv) {
    Node m = {.key = 11, .left = NULL, .right = NULL, .parent = NULL };
    Node n = {.key = 10, .left = NULL, .right = NULL, .parent = NULL };
    Node o = {.key = 15, .left = NULL, .right = NULL, .parent = NULL };
    Node p = {.key = 12, .left = NULL, .right = NULL, .parent = NULL };
    Node q = {.key = 27, .left = NULL, .right = NULL, .parent = NULL };
    Node r = {.key = 25, .left = NULL, .right = NULL, .parent = NULL };
    Node s = {.key = 17, .left = NULL, .right = NULL, .parent = NULL };
    Node t = {.key = 22, .left = NULL, .right = NULL, .parent = NULL };

    m.left   = &n;
    m.right  = &o;
    m.parent = NULL;

    n.left   = NULL;
    n.right  = NULL;
    n.parent = &m;
    
    o.left   = &p;
    o.right  = &q;
    o.parent = &m;

    p.left   = NULL;
    p.right  = NULL;
    p.parent = &o;

    q.left   = &r;
    q.right  = NULL;
    q.parent = &o; 

    r.left   = NULL;
    r.right  = NULL;
    r.parent = &q;

    BST *b = new BST();           /* Initialize BST         */
    b->SET_ROOT(&m);              /* Set the root of b      */
	b->SET_SIZE(6); 			  /* Set size in this case  */
    
    if (argc == 1) {
       printf("Usage: binarySearch [ORD|MAX|SUC|INS|DEL]\n");
       return 0;
    }

    if (strcmp (argv[1], "ORD") == 0) 
        testInorderTraversal(b);            /*    InOrder Traversal   */
    else if (strcmp (argv[1], "MAX") == 0) 
        testFindmax(b);                     /*  FindMax value of BST  */
    else if (strcmp (argv[1], "SUC") == 0) 
        testSuccessor(b, 15);               /*   Find successor at x  */
    else if (strcmp (argv[1], "INS") == 0) 
        testDeletion(b, 15);                /*  Delete Node of key x  */
    else if (strcmp (argv[1], "DEL") == 0) 
        testInsertion(b, &s);               /* Insert Node n into BST */
    else 
       printf("Usage: binarySearch [ORD|MAX|SUC|INS|DEL]\n");
    return 0;
}

void testInorderTraversal(BST *b) {
    /* Inorder traversal */
    printf("Inorder Traversal Test:\n");
    b->traverseinorder();
}
    
void testFindmax(BST *b) {
    /* findMax() in BST  */ 
    printf("Findmax Value Test:\n");
    int max = b->findmax();
    printf("\t-->Maximum value node in the tree is %d.\n", max);
}

void testSuccessor(BST *b, int x) {
    /* successor test */
    printf("Find Successor of Node x:\n");
    int successor = b->successor(x); 
    printf("\t-->Successor of node x is %d.\n", successor);

}

void testDeletion(BST *b, int x) {
    /* Delete Node with key x */
    printf("BST tree SIZE BEFORE Node x deletion:\n");
	printf("Size : %d\n", b->GET_SIZE());
    printf("BST tree BEFORE Node x deletion:\n");
    b->traverseinorder();
    b->deleteNode(x);
    printf("BST tree SIZE AFTER Node x deletion:\n");
	printf("Size : %d\n", b->GET_SIZE());
    printf("BST tree AFTER Node x deletion:\n");
    b->traverseinorder();
}

void testInsertion(BST* b, Node *n) {
    /* Insert Node x into BST */ 
    printf("BST tree size BEFORE Node x insertion:\n");
	printf("Size : %d\n", b->GET_SIZE());
    printf("BST tree BEFORE Node x insertion:\n");
    b->traverseinorder();
    b->insertNode(n);  // Node Insert
    printf("BST tree size AFTER Node x insertion:\n");
	printf("Size : %d\n", b->GET_SIZE());
    printf("BST tree AFTER Node x insertion:\n");
    b->traverseinorder();
}
