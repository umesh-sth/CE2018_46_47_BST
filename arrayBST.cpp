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
	int index = 0;
	bool a= true;
	while (a==true){
		if (A[index] == data){
			
			return true;
			break;
		}
		else if (A[index] <data){
			index = (2 * index + 2);
			
		}
		else if (A[index] > data){
			index = (2 * index + 1);
			
		}
		else
			a=false;
	}
	return a;
}




/*
void arrayBST::preorderTraversal(){
	
		int index=0;
		cout<<A[index]<<endl;
			while(true){
				int index = 0;
				index = (2 * index + 2);
				cout<<A[index]<<endl;
			}
			while(true){
				index=0;
				index = (2 * index + 1);
				cout<<A[index]<<endl;
				
		}	
	}*/
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
	if( arr.search(15)== true)
		cout<<" 15 is present";
	else
		cout<<"15 is not present";
		
	if( arr.search(26)== true)
		cout<<" 25 is present";
	else
		cout<<"25 is not present";
//	arr.preorder(2);

}






