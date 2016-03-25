// main.cpp
//
// Simple main for testing C++ classes.
// 2016 (c) zubernetes
#include "bst.h"

void testInorderTraversal(BST*); 
void testFindmax(BST*);

int main(int argc, char** argv) {
    int max, successor;
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
    
    /* Initialize BST */
    BST *b = new BST();

    /* Set the root of b */
    b->SET_ROOT(&m);

    testInorderTraversal(b);

    /* findmax() test */
    max = b->findmax();

    /* successor test */
    successor = b->successor(15);
    printf("successor : %d\n", successor);

    /* deleteNode on 'o' */
    b->deleteNode(15);

    printf("After deletion\n");
    b->traverseinorder();

    // Insertion test 
    printf("Insertion Test\n");

    BST *test = new BST();

    test->insertNode(&s);
    test->insertNode(&t);

    test->traverseinorder();

    return 0;
}

void testInorderTraversal(BST *b) {
    /* Inorder traversal */
    printf("Inorder Traversal Test:\n");
    b->traverseinorder();
}
    
