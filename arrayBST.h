#include "bst.h"
#define Max_Size 20


class arrayBST:public BinarySearchTree{
	private:
		int A[Max_Size];
	public:
		arrayBST();
		void printElements();
		
		
		int get_left_child(int index){
    if(A[index]!=0 && (2*index)<=Max_Size){
        return 2*index;
    }
    return -1;
}



int get_right_child(int index){
    if(A[index]!=0 && (2*index+1)<=Max_Size){
        return 2*index+1;
    }
    return -1;
}


void preorder(int index){
	if(index>0 && A[index]!=0)
    {
        std::cout<<element[index]<<std::endl;
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}
		
		
};
