#include "bst.h"
#define Max_Size 20


class arrayBST:public BinarySearchTree{
	private:
		int A[Max_Size];
	public:
		arrayBST();
		void printElements();
		void add(int data);
	
		bool search(int data);
		
		
		
};
