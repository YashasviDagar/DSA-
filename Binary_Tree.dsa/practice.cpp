#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    cout << "For indertion in left enter:" << endl;
    root->left = buildTree(root->left);
    cout << "For insertion in right enter:" << endl;
    root->right = buildTree(root->right);
    return root;
}

int heightOfBinaryTree(node *root)
{
    // Write your code here.
    if (root == NULL)
        return 0;
    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);
    return max(left, right) + 1;
}

pair<int,int> diameteroptimised(node* root){
    if(root==NULL) return {0,0};
    pair<int,int> left = diameteroptimised(root->left);
    pair<int,int> right = diameteroptimised(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second;
    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;
    return ans;
}

int diameter(node* root){
    return diameteroptimised(root).first;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    heightOfBinaryTree(root);
   
    /*
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    root = buildTree(root);
    levelOrderTransversal(root);
    */
    return 0;
}
