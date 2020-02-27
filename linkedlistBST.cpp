#include"linkedlistBST.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

node::node(){
    data=0;
    left=right=NULL;
}

node::node(int value){
    data=value;
    left=right=NULL;
}

node::~node(){}


LinkedBST::LinkedBST(){
}

LinkedBST::~LinkedBST(){}

void LinkedBST::add(int data){
}

void LinkedBST::preorderTraversal(){}


void LinkedBST::add(node *root,int data){
if (root->data==0){
    root->data=data;
}else{
        if (data < root->data){
            if (!root->left){
                node *newnode=new node(data);
                root->left=newnode;
            }
            else{
                add(root->left,data);
            }
        }
        else if (data > root->data){
            if (!root->right){
                node *newnode=new node(data);
                root->right=newnode;
            }
            else{
                add(root->right,data);
            }
        }
    }
}

bool LinkedBST::search(node *root,int targetKey){
    if(root->data==0){
     cout<<"It is an empty tree"<<endl;
    }
    else{
        node *p=new node();
        p=root;
        while(p){
            if(targetKey>p->data){
                p=p->right;
            }
            else if(targetKey<p->data){
                p=p->left;
            }
            else if(targetKey==p->data){
                return true;

            }
            else{
                return false;
            }
        }
    }
    return false;
}


void LinkedBST::preorderTraversal(node* root) {
    if (!root)
    return;


    cout << root->data << "\t";


    preorderTraversal(root->left);


    preorderTraversal(root->right);
}

void LinkedBST::inorderTraversal(node* root) {
    if (!root)
    return;


    inorderTraversal(root->left);

    cout << root->data << "\t";


    inorderTraversal(root->right);
}

int LinkedBST::min(){
    node* p= new node;
    p= &root;
    while(p->left!= NULL){
        p= p->left;
    }
    return p->data;
}


int LinkedBST::max(){
	node *p=new node();
        p=&root;
        while(p ->right !=0)
        		p= p->right;

	return p->data;


}

void LinkedBST::deleteNode(int val)
{
    deleteFromTree(&root,val);
}


void LinkedBST::deleteFromTree(node* root,int val){
	
	int dat;
	if(root==NULL){
		cout<<"tree is empty"<<endl;
		return;
	}
	if(search(root,val)==true){
		if(val<root->data){
			node* temp=new node();
			temp=root->left;
			if(root->left->data==val && root->left->left==NULL && root->left->right==NULL){
				root->left=NULL;
			}
			deleteFromTree(temp,val);
			return;
		}
		else if(val>root->data){
			node* temp=new node();
			temp=root->right;
			if(root->right->data==val && root->right->left==NULL && root->right->right==NULL){
				root->right=NULL;
			}
			deleteFromTree(temp,val);
			return;
		}
		else{
			if(root->left==NULL && root->right==NULL){
				delete root;
				root=NULL;
				return;
			}
			else if(root->left==NULL){
				node* temp=new node();
				temp=root->right;
				root->data=root->right->data;
				root->right=root->right->right;
				delete temp;
				return;
			}
			else if(root->right==NULL){
				node* temp=new node();
				temp=root->left;
				root->data=root->left->data;
				root->left=root->left->left;
				delete temp;
				return;
			}
			else{
				node* nodetoDelete=new node();
				nodetoDelete=root;
				node* newNode=new node();
				newNode=root->left;
				while(newNode->right!=NULL){
					newNode=newNode->right;
				}
				dat=newNode->data;
				deleteFromTree(nodetoDelete,newNode->data);
				root->data=dat;
				return;
			}
		}
	}
	
	else{
		cout<<"The node to be deleted not found in the tree\n";
		exit(0);
		}
}		
	


int main(){
	
	LinkedBST s;

	s.add(&s.root,46);
	s.add(&s.root,19);
	s.add(&s.root,17);
	s.add(&s.root,33);
	s.add(&s.root,81);
	s.add(&s.root,51);
	
	cout<<"Preorder Traversal of the tree is"<<endl;
	s.preorderTraversal(&s.root);
	cout<<endl;
	
	cout<<"\n";
	
	cout<<"Inorder Traversal of the tree is"<<endl;
	s.inorderTraversal(&s.root);
	cout<<endl;
	
	cout<<"\n";

	cout<<s.min()<<" is the min node"<<endl;
	
	cout<<"\n";
	
	cout<<s.max()<<" is the max node"<<endl;
	
	cout<<"\n";

    int number;
	cout<<"Enter a number you want to search  in the tree"<<endl;
	cin>>number;
	if(s.search(&s.root,number)==true){
		cout<<number<<" is in the tree.\n";
		}
	else{
		cout<<number<<" is not in the tree.\n";
		}	
		
	cout<<"\n";
	
	int n;
	cout<<"Enter the number you want to delete\n";
	cin>>n;
	s.deleteNode(n);
	
	cout<<"\n";

	cout<<"After deleting:\n";
	cout<<"\n";
	
	cout<<"Preorder Traversal of the tree is"<<endl;
	s.preorderTraversal(&s.root);
	cout<<endl;
	
	cout<<"\n";
	
	cout<<"Inorder Traversal of the tree is"<<endl;
	s.inorderTraversal(&s.root);
	cout<<endl;
	
	cout<<"\n";

	cout<<s.min()<<" is the min node"<<endl;
	
	cout<<"\n";
	
	cout<<s.max()<<" is the max node"<<endl;

}
