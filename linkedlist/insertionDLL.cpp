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
Node* insertHead_before(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}
Node* insertbeforeTail(Node* head,int val){
    if(head->next==NULL) return insertHead_before(head,val);
    Node* tail = head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}
Node* insertbefore_kth(Node* head,int k, int val){
    if(k==1) return insertHead_before(head,val);
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp= temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node( val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;

}
void insertbefore_node(Node* node,int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node,prev);
    prev->next=newNode;
    node->back=newNode;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    int val;
    cin>>val;
  vector<int> arr = {1,3,5,6,7};
  Node* head = convertarr2DLL(arr);
//   head=insertbefore_kth(head,3,val);
  insertbefore_node(head->next,val);
  print(head);
  return 0;
}