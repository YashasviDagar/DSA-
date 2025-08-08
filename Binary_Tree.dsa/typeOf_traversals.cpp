#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1) return NULL;
    cout<<"For indertion in left enter:"<<endl;
    root->left=buildTree(root->left);
    cout<<"For insertion in right enter:"<<endl;
    root->right=buildTree(root->right);
    return root;
}

void inorder(node* root){// L N R -> Left(L)  Print(N)  Right(R)
    if(root == NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){// N L R
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(node* root){// L R N
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
  node* root = NULL;
  //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
  root = buildTree(root);
//   cout<<" inorder transversal: "<<endl;
//   inorder(root);

//   cout<<" preorder transversal: "<<endl;
//   preorder(root);

  cout<<" postorder transversal: "<<endl;
  postorder(root);
  return 0;
}