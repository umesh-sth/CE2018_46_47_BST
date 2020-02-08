#include "arrayBST.h"
#include<iostream>
#include<stddef.h>
using namespace std;
int count = 0; // count for tree
arrayBST::arrayBST(){
	for(int i=0;i<Max_Size;i++){
		A[i]=NULL;
	}

}

void arrayBST::add(int data){
	int index = 0;
	while (true){
		if (A[index] == 0){
			A[index] = data;
			count++;
			break;
		}
		else if (A[index] <= data){
			index = (2 * index + 2);
			count++;
		}
		else if (A[index] >= data){
			index = (2 * index + 1);
			count++;
		}
	}
}
void arrayBST::printElements(){
	for(int i=0;i<Max_Size;i++)
		cout<< A[i]<<"   " <<endl;
	}

bool arrayBST::search(int data){
	int currentIndex=0;
	while(true){
		if(A[currentIndex]==0)
			return false;
		if(data==A[currentIndex])
			return true;
		

		else if(data>A[currentIndex]){
			currentIndex=(2*currentIndex)+2;

		}
		else if(data < A[currentIndex]){
			currentIndex=(2*currentIndex)+1;

		}
	}
}


int arrayBST::returnIndex(int data){
	int currentIndex=0;

	while(true){
		if(A[currentIndex]==0){
			break;
		}
		if(data==A[currentIndex]){
			return currentIndex;
			break;
		}

		else if(data>A[currentIndex]){
			currentIndex=(2*currentIndex)+2;

		}
		else if(data < A[currentIndex]){
			currentIndex=(2*currentIndex)+1;

		}
	}
}

int arrayBST::get_left_child(int index){
    if((A[index]!=0) && ((2*index+1) <= Max_Size)){
			return 2*index+1;

		}
		else{
			return -1;
		}
}

int arrayBST::get_right_child(int index){
    if(A[index]!=0 && (2*index+2)<=Max_Size){
        return 2*index+2;
    }
    else
    	return -1;
}

void arrayBST::preorder(int index){
	if(index>=0 && A[index]!=0)
    {
        std::cout<<A[index]<<std::endl;
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}
void arrayBST::inOrder(int index){
	if(index>=0 && A[index]!=0)
    {

        inOrder(get_left_child(index));
        std::cout<<A[index]<<std::endl;
        inOrder(get_right_child(index));
    }
}

int arrayBST::maxNode(){
 int index = 0;
 while(A[arrayBST::get_right_child(index)]!=0){
 	index = index * 2 + 2 ;
 	}
 	return A[index];

 }


int arrayBST::min(){
    int index= 0;
    while(A[arrayBST::get_left_child(index)]!=0){
        index= 2* index + 1;
    }

    return A[index];

}

int arrayBST::minNode(int index){
	while(A[arrayBST::get_left_child(index)]!=0){
        index= 2* index + 1;
    }

    return A[index];
}

void arrayBST::deleteNode(int data){
	if(arrayBST::search(data)==false)
		cout<<"Sorry the BST doesnt contain"<<data <<" . "<<endl;
	if(arrayBST::search(data)==true){
		int currentIndex = arrayBST::returnIndex(data);
		int leftChild = A[arrayBST::get_left_child(currentIndex)];
		int rightChild = A[arrayBST::get_right_child(currentIndex)];
		
		if(leftChild==NULL && rightChild== NULL){
			A[currentIndex]=NULL;
			cout<<"Delete Sucessfull!!"<<endl;
		}
		else if(leftChild==NULL && rightChild!=NULL){
			A[currentIndex] = NULL;
			A[currentIndex]=rightChild;
			A[arrayBST::returnIndex(rightChild)]= NULL;
			cout<<"Delete Sucessfull!!"<<endl;
		}
		else if(leftChild!=NULL && rightChild==NULL){
			A[currentIndex] = NULL;
			A[currentIndex]= leftChild;
			A[arrayBST::returnIndex(leftChild)]= NULL;
			cout<<"Delete Sucessfull!!"<<endl;
		}
		else if(leftChild!=NULL && rightChild!=NULL){
			int index = arrayBST::returnIndex(rightChild);
			int minNodeIndex = arrayBST::returnIndex(arrayBST::minNode(index));
			A[currentIndex] = NULL;
			A[currentIndex] = arrayBST::minNode(index);
			A[minNodeIndex] = NULL;
			cout<<"Delete Sucessfull!!"<<endl;
					
		}
		else 
			return;
	}
}

	



int main(){
	arrayBST arr;
	arr.add(40);
	arr.add(50);
	arr.add(20);
	arr.add(25);
	arr.add(15);
	arr.add(56);
	arr.add(46);
	arr.add(44);
	arr.printElements();
	if(arr.search(25)==true)
		cout<<"25 is in the binary tree."<<endl;
	else
		cout<<"Search of 25 Unsucessfull."<<endl;
	if(arr.search(26)==true)
		cout<<"26 is in the binary tree."<<endl;
	else
		cout<<"Search of 26 Unsucessfull."<<endl;
	cout<<"Preorder Traversal: \n"<<endl;
	arr.preorder(0);

	cout<<"MAx Node \n";
	cout<<arr.maxNode()<<endl;


    cout<<"Min value:\n";
    cout<<arr.min()<<endl;

cout<<"inORDER Traversal: \n"<<endl;
	arr.inOrder(0);
	arr.deleteNode(40);
	arr.printElements();
}
