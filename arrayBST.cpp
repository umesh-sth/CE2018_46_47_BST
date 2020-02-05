#include "arrayBST.h"
#include<iostream>
#include<stddef.h>
using namespace std;
int count = 0; // count for tree
arrayBST::arrayBST(){
	for(int i=0;i<Max_Size;i++){
		A[i]=0;
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
	for(int i=0;i<7;i++)
		cout<< A[i]<<"   " <<endl;
	}

bool arrayBST::search(int data){
	int currentIndex=0;
	cout<<"Searching "<<data<<endl;

	while(true){
		if(A[currentIndex]==0){
			cout<<"Key Not Found!"<<endl;
			break;
		}
		if(data==A[currentIndex]){
			cout<<"Key  Found! at currentIndex "<< currentIndex << endl;
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



int main(){
	arrayBST arr;
	arr.add(40);
	arr.add(50);
	arr.add(20);
	arr.add(25);
	arr.add(15);
	arr.add(56);
	arr.add(46);
	arr.printElements();
	arr.search(25);
	arr.search(26);
	cout<<"Preorder Traversal:"<<endl;
	arr.preorder(0);

	cout<<"MAx Node";
	cout<<arr.maxNode();


    cout<<"Min value:\n";
    cout<<arr.min();

}






