#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data = data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertarr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1 ; i<arr.size() ; i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;//prev->next=temp;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
  vector<int> arr = {1,3,5,6,7};
  Node* head = convertarr2DLL(arr);
  print(head);
  return 0;
}