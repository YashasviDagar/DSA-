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

void levelOrderTransversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void treeFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root:"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
  node* root = NULL;
    treeFromLevelOrder(root);
    levelOrderTransversal(root);
  /*
  //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
  root = buildTree(root);
  levelOrderTransversal(root);
  */
  return 0;
}