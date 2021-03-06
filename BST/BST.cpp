//Binary search tree Build and print 

#include<bits/stdc++.h>
using namespace std;

//ode class for BST

class Node{
  public:
  
   int data;
   Node*left;
   Node*right;
   
   Node(int data){
       this->data=data;
       left=NULL;
       right=NULL;
   }
   
};

// insert any data into binary search tree

Node* insertInBST(int data,Node*root){
    if(root==NULL)
      {
         Node*node= new Node(data);
         return node;
      }
     
     if(data<root->data)
      root->left=insertInBST(data,root->left);
     else
      root->right=insertInBST(data,root->right);
      
     return root;
}

// search an element in bst 

Node* search(Node* root,int key){
    if(root==NULL)
      return NULL;
    
    if(root->data==key)  
      return root;
    
    if(key<root->data)
     search(root->left,key);
    else
     search(root->right,key);
}

// delete Node from BST

Node* deleteFromBST(Node* root, int key){
    
    if(root==NULL)
      return NULL;
    
    if(key<root->data){
        root->left=deleteFromBST(root->left,key);
        return root;
    } 
    if(key>root->data){
        root->right= deleteFromBST(root->right,key);
        return root;
    } 
    if(root->data==key){
        
        if(root->left ==NULL && root->right ==NULL)
         { 
             delete root;
             return NULL;
             
         }  
        
        if(root->left !=NULL && root->right ==NULL)
          {
              Node* temp=root->left;
              delete root;
              return temp;
          }
          
        if(root->left ==NULL && root->right !=NULL)
           {
              Node* temp=root->right;
              delete root;
              return temp;
          }
          
        Node*inOPrec=root->right;  
        while(inOPrec->left!=NULL)
          inOPrec=inOPrec->left;

        int temp=root->data;
        root->data=inOPrec->data;
        int data=inOPrec->data;
        root->right =deleteFromBST(root->right,data);
        return root;
    } 

}

// inorder print of BST (result in sorted data)

void inOrder(Node* root){
    if(root==NULL)
     return ;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// Take input and insert in BST

Node* bulidBST(){
    int x;
    cin>>x;
    Node* root=NULL;
    while(x!=-1){
      root= insertInBST(x,root);
        cin>>x;
    }
    return root;
}

int main(){
    Node* root;
    root=bulidBST();
    inOrder(root);
}