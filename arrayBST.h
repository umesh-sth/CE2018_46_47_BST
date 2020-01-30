#include "bst.h"
#define Max_Size 20


class arrayBST:public BinarySearchTree{
	private:
		int A[Max_Size];
	public:
		arrayBST();
		void add(int data);
		//void preorderTraversal();
		bool search(int data);
		void printElements();
		
};
