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

struct Date {
    int y;
    int m;
    int d;
};

class BST {
public:
BST();
	// ~BST();				  // destructor deletes all nodes 

	void insertNode(Node *n); // inserts a node n into the tree
	int deleteNode(int z); 	  // deletes the first node with a value x
	int successor(int x);     // returns the successor to the node x
	void traverseinorder();   // prints the nodes in the tree in order
	int findmax(); 		      // returns the manimum value node in the tree
private:
	Node *root;	// pointer to first node
	int size;	// number of nodes in the tree
};

BST::BST() { }
void BST::insertNode(Node *n) { }
	
#endif 
