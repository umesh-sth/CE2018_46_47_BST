#include "arrayBST.h"
#include<iostream>
arrayBST::arrayBST(){
	for(int i=0;i<Max_Size;i++){
		this->A[i]=0;
	}

}

arrayBST::void add(int data){
	if(A[0]==0)
		this->A[0] = data;
	else
		for(int i=0;i<Max_Size;){
			if(data < this->A[i])
				i = 2*i;
			else
				i = 2*i+1;

			if(this->A[i]==0){
				this->A[i]=data;
				break;

	}
	this->A[0]=this->A[0]+1;


}
arrayBST::printElements(){
	for(int i=0;i<Max_Size;i++)
		cout<< A[i]<<"   " ;
	}
int main(){
	arrayBST arr;
	arr.add(40);
	arr.printElements();
	

}






