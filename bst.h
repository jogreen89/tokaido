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
	// ~BST();				        // destructor deletes all nodes 

    /* Helper methods */
    Node* getRoot();
    Node* getLeftChild(Node*);
    Node* getRightChild(Node*);
    Node* getParent(Node*);
    int   getKey(Node*);
    int   getSize();
    void  setLeftChild(Node*); 
    void  setRightChild(Node*); 
    void  setParent(Node*);
    void  setRoot(Node*);

    void  TRAVERSE(Node*);
    void  TRANSPLANT(Node*,Node*);
    int   TREE_MAXIMUM(Node*);
    int   TREE_SUCCESSOR(Node*);
    Node* TREE_SEARCH(Node*,int);
    
    
    /* Required methods */
	void insertNode(Node*);         // inserts a node n into the tree
	int  deleteNode(int);           // deletes the first node with a value x
	int  successor(int);            // returns the successor to the node x
	int  findmax();                 // returns maximum value node in the tree
	void traverseinorder();         // prints the nodes in the tree in order

private:
	Node *root;	                   // pointer to first node
	int size;	                   // number of nodes in the tree
};

BST::BST() {
    /* An empty BST() */
    root = NULL;
    size = 0;
}

BST::BST(Node *n) {
    /* Initialize BST() with root Node */
    root = n;
}

// Helper Methods

void BST::setLeftChild(Node *n) {
    root->left = n;
}

void BST::setRightChild(Node *n) {
    root->right = n;
}

void BST::setRoot(Node *n) {
    root = n;
}
    
Node* BST::getRoot() {
    return root;
}

Node* BST::getLeftChild(Node *n) {
    return n->left;
}

Node* BST::getRightChild(Node *n) {
    return n->right;
}

Node* BST::getParent(Node *n) {
    return n->parent;
}

int BST::getKey(Node *n) {
    return n->key;
}

int BST::getSize() {
    return size;
}

void BST::insertNode(Node *n) {
    if (getRoot() == NULL && getSize() == 0) {
        root = n;
        size++;
    } else if (root->key < n->key) {
        printf("Node n is <\n");
        setLeftChild(n);
        size++;
    } else if (getRoot()->key > n->key) {
        printf("Node n is >\n");
        setRightChild(n);
        size++;
    } else {
        printf("Else block\n");
        size++;
    }
}

void BST::traverseinorder() {
    Node *n = getRoot();
    TRAVERSE(n);
}

void BST::TRAVERSE(Node *n) { 
    if (n != NULL) { 
        TRAVERSE(n->left);
        printf("key : %d\n",n->key);
        TRAVERSE(n->right);
    }
} 

int BST::findmax() {
    int x;
    Node *n = getRoot();
    x = TREE_MAXIMUM(n);
    return x;
}

int BST::TREE_MAXIMUM(Node *n) {
    while (n->right != NULL)
        n = n->right;
    return n->key; 
}

int BST::successor(int x) {
    int k;     // Successor Key
    // Need to do a TREE_SEARCH(Node*, int)
    Node *n;
    Node *r = getRoot();
    n = TREE_SEARCH(r, x);
    k = TREE_SUCCESSOR(n);
    return k;
}

int BST::TREE_SUCCESSOR(Node *n) {
    Node *y;
    if (n->right != NULL)
        return TREE_MAXIMUM(n->right);
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

#endif 
