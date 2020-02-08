//#include "bst.h"
#define Max_Size 20


//class arrayBST:public BinarySearchTree{
class arrayBST{
	private:
		int A[Max_Size];
	public:
		arrayBST();
		void printElements();
		void add(int data);
		bool search(int data);
		void preorder(int data);
		int get_right_child(int index);
		int get_left_child(int index);
		void inOrder(int index);
		int maxNode();
		int returnIndex(int data);
		void deleteNode(int data);
		int min();
		int minNode(int index);
};
