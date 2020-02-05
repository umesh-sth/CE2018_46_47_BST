#include "bst.h"
#include <iostream>


class node
{
public:
    int data;
    node* left ;
    node* right;
    node();
    node(int);
    ~node();
};


class LinkedBST:public BinarySearchTree{

    public:
    node root;
    LinkedBST();
    ~LinkedBST();
    void preorderTraversal();
    void preorderTraversal(node *root);
    void add(int data);
    void add(node *root,int data);
    bool search(int data);
    bool search(node *root,int targetKey);
    int min()
    int max();
};


