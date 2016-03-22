// bst.h
//
// A class-based binary-search tree.
// 2016 (c) zubernetes
#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

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
    void  traverse(Node*);
    Node* getRoot();
    Node* getLeftChild(Node*);
    Node* getRightChild(Node*);
    Node* getParent(Node*);
    unsigned int getKey(Node*);
    unsigned int getSize();
    unsigned int TREE_MAXIMUM(Node*);

    // Helper methods (cont.)

    void  setLeftChild(Node*); 
    void  setRightChild(Node*); 
    void  setParent(Node*);
    void  setRoot(Node*);

    // Required methods (class)

	void insertNode(Node *n);       // inserts a node n into the tree
	unsigned int deleteNode(int z); // deletes the first node with a value x
	unsigned int successor(int x);  // returns the successor to the node x
	unsigned int findmax();         // returns maximum value node in the tree
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

void BST::traverseinorder() {
    Node *n = root;
    traverse(n);
}

void BST::traverse(Node *n) {
    if (n != NULL) {
        traverse(n->left);
        printf("key : %d\n",n->key);
        traverse(n->right);
    }
} 

unsigned int BST::findmax() {
    printf("findmax\n");
    return 5;
}

unsigned int BST::TREE_MAXIMUM(Node *n) {
    while (n->right != NULL)
        n = n->right;
    return (unsigned int)n->key; 
}

#endif 
