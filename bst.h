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
	// ~BST();				        // destructor deletes all nodes 

    // Helper methods
    Node* getRoot();
    Node* getLeftChild(Node*);
    Node* getRightChild(Node*);
    Node* getParent(Node*);
    unsigned int getKey(Node*);
    unsigned int getSize();

    // Helper methods (cont.)

    void  setLeftChild(Node*); 
    void  setRightChild(Node*); 
    void  setParent(Node*);

    // Required methods (class)

	void insertNode(Node *n);      // inserts a node n into the tree
	unsigned int deleteNode(int z);// deletes the first node with a value x
	unsigned int successor(int x); // returns the successor to the node x
	void traverseinorder(Node*);   // prints the nodes in the tree in order
	unsigned int findmax(Node*);   // returns the manimum value node in the tree
private:
	Node *root;	                   // pointer to first node
	int size;	                   // number of nodes in the tree
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

void BST::setRightChild(Node *n) {
    root->right = n;
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

unsigned int BST::getKey(Node *n) {
    return n->key;
}

unsigned int BST::getSize() {
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

void BST::traverseinorder(Node *n) {
    if (n != NULL) {
        traverseinorder(n->left);
        printf("key : %d\n",n->key);
        traverseinorder(n->right);
    }
}

unsigned int BST::findmax(Node *n) {
    printf("findmax\n");
    return 5;
}

#endif 
