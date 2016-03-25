// bst.h
//
// A class-based binary-search tree.
// 2016 (c) zubernetes
#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

#include "Node.h"

class BST {
public:
    BST();
    BST(Node*);
    // ~BST();              // destructor deletes all nodes 

    /* Helper methods */
	int   GET_SIZE();
    void  TRAVERSE(Node*);
    void  TRANSPLANT(Node*,Node*);
    Node* TREE_MAXIMUM(Node*);
    Node* TREE_MINIMUM(Node*);
    int   TREE_SUCCESSOR(Node*);
    Node* TREE_SEARCH(Node*,int);
    void  SET_ROOT(Node*);
	void  SET_SIZE(int);
    
    /* Required methods */
    void insertNode(Node*);         // inserts a node n into the tree
    int  deleteNode(int);           // deletes the first node with a value x
    int  successor(int);            // returns the successor to the node x
    int  findmax();                 // returns maximum value node in the tree
    void traverseinorder();         // prints the nodes in the tree in order

private:
    Node *root;                     // pointer to first node
    int size;                       // number of nodes in the tree
};

BST::BST() {
    /* An empty BST() */
    root = NULL;
    size = 0;
}

int BST::GET_SIZE() {
	return size;
}

void BST::TRAVERSE(Node *n) { 
    if (n != NULL) { 
        TRAVERSE(n->left);
        printf("key : %d\n",n->key);
        TRAVERSE(n->right);
    }
} 

void BST::TRANSPLANT(Node *u, Node *v) {
    if (u->parent == NULL) 
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else 
        u->parent->right = v;
    if (v != NULL) 
        v->parent = u->parent;
}

Node* BST::TREE_MAXIMUM(Node *n) {
    while (n->right != NULL)
        n = n->right;
    return n; 
}

Node* BST::TREE_MINIMUM(Node *n) {
    while(n->left != NULL)
        n = n->left;
    return n;
}

int BST::TREE_SUCCESSOR(Node *n) {
    Node *y;
    if (n->right != NULL)
        return TREE_MAXIMUM(n->right)->key;
    y = n->parent; 

    while (y != NULL && n == y->right) {
        n = y;
        y = y->parent;
    }
    return y->key;
}

Node* BST::TREE_SEARCH(Node *n, int k) {
    if (n == NULL || k == n->key)
        return n;
    if (k < n->key) 
        return TREE_SEARCH(n->left, k);
    else
        return TREE_SEARCH(n->right, k);
}

void BST::SET_ROOT(Node *n) {
    root = n;
}

void BST::SET_SIZE(int x) {
	size = x;
}

void BST::insertNode(Node *n) {
    Node *y = NULL;
    Node *x = root;
    while (x != NULL) {
        y = x;
        if (n->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    n->parent = y;
    if (y == NULL)
        root = n;
    else if (n->key < y->key) 
        y->left = n;
    else
        y->right = n;
	size++;
}

int BST::deleteNode(int x) {
    // Get "T's root" to begin
    Node *n, *y;
    Node *r = root;
    n = TREE_SEARCH(r, x);

    if (n->left == NULL)                /* z has no left child */
        TRANSPLANT(n, n->right);
    else if (n->right == NULL)
        TRANSPLANT(n, n->left);         /* z has just a left child */
    else {
        // z has two children
        y = TREE_MINIMUM(n->right); /* y is z's successor      */
        if (y->parent != n) {
            // y lies within z's right subtree but it
            // is not the root of this subtree
            TRANSPLANT(y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        // Replace z by y.
        TRANSPLANT(n, y);
        y->left = n->left;
        y->left->parent = y;
    }
	size--;
    return 0;
}

int BST::successor(int x) {
    int k;          // Successor Key
    // Need to do a TREE_SEARCH(Node*, int)
    Node *n;
    Node *r = root;
    n = TREE_SEARCH(r, x);
    k = TREE_SUCCESSOR(n);
    return k;
}

int BST::findmax() {
    int x;
    Node *n = root;
    x = TREE_MAXIMUM(n)->key;
    return x;
}

void BST::traverseinorder() {
    TRAVERSE(root);
}

#endif 
