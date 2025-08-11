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

void iterative_inorder(node* root){// L N R -> Left(L)  Print(N)  Right(R)
    if(root == NULL) return ;
    
    stack<node*> st;
    
    while(true){
        if(root!=NULL){
            st.push(root);
            root=root->left;
        }else{ 
            if(st.empty()) break;
            root=st.top();
            st.pop();
            cout<<root->data<<" ";
            root=root->right;
        }
    }
}

void iterative_preorder(node* root){// N L R
    if(root == NULL) return ;
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        cout<<root->data<<" ";
        st.pop();
        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) st.push(root->left);
    }
    
}



int main(){
  node* root = NULL;
  //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
  root = buildTree(root);
  cout<<" inorder transversal: "<<endl;
  iterative_inorder(root);

//   cout<<" preorder transversal: "<<endl;
//   iterative_preorder(root);

//   cout<<" postorder transversal: "<<endl;
//   iterative_postorder(root);
  return 0;
}