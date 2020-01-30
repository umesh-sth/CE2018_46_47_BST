#include "bst.h"
class Node{
	int data;
	Node* left;
	Node* right;
};

class linkedBST:public BinarySearchTree{
	private:
		NOde* root;

	public:
		void add(int data);
		void preorderTraversal();
		bool search(int data);
	

}
