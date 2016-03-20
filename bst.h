// bst.h
//
// A class-based binary-search tree.
// 2016 (c) zubernetes
#ifndef BST_H
#define BST_H

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int key;
	Node *left;
	Node *right;
	Node *parent;
};

class BST {
public:
    BST();
	// ~BST();				  // destructor deletes all nodes 

    // Helper methods
    Node* getRoot();
    Node* getLeftChild(Node*);
    int   getSize();
    void  setLeftChild(Node*); 

	void insertNode(Node *n); // inserts a node n into the tree
	int deleteNode(int z); 	  // deletes the first node with a value x
	int successor(int x);     // returns the successor to the node x
	void traverseinorder();   // prints the nodes in the tree in order
	int findmax(); 		      // returns the manimum value node in the tree
private:
	Node *root;	// pointer to first node
	int size;	// number of nodes in the tree
};

BST::BST() {
    /* An empty BST() */
    root = NULL;
    size = 0;
}

// Helper Methods

void BST::setLeftChild(Node *n) {
    root->left = n;
}

Node* BST::getRoot() {
    return root;
}

Node* BST::getLeftChild(Node *n) {
    return n->left;
}

int BST::getSize() {
    return size;
}

void BST::insertNode(Node *n) {
    if (getRoot() == NULL && getSize() == 0) {
        root = n;
        size++;
    } else if (getRoot()->key < n->key) {
        printf("Node n is <\n");
        setLeftChild(n);
        size++;
    } else if (getRoot()->key > n->key) {
        printf("Node n is >\n");
        size++;
    } else {
        printf("Else block\n");
        size++;
    }
}
	
#endif 
