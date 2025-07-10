#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  public:
  Node(int data1,Node* next1){
    data=data1;
    next=next1;
  }
  public:
  Node(int data1){
    data=data1;
    next=nullptr;
  }
};

Node* convertarrToLL(vector<int> arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1 ; i<arr.size() ; i++){
    Node* temp= new Node(arr[i]);
    mover->next=temp;
    mover=temp;
  }
  return head;
}
int lengthofLL(Node* head){
  int cnt=0;
  Node* temp = head;
  while(temp){
    temp=temp->next; 
    cnt++;
  }
  return cnt;
}
int search(Node* head,int val){
  Node* temp=head;
  while(temp){
    if(temp->data==val) return 1;
    temp=temp->next;
  }
  return 0;
}
Node* delete_head(Node* head){
  if(NULL==head) return head;
  Node* temp = head;
  head= head->next;
  free(temp); //delete temp; also works;
  return head;
}
Node* removes_tail(Node* head){
  if(head==NULL || head->next==NULL) return NULL;
  Node* temp = head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  free(temp->next); //since temp is at second last free last element!
  temp->next=nullptr;//since last second ele pointed to last element's storage we assign it to nullptr!
  return head;
}
void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
  vector<int> arr={1,3,5,2,5,8,7,10};
  Node* head = convertarrToLL(arr);
  // cout<<head->data; //returning the head of the array!

  // Node* temp = head;
  // while(temp){
  //   cout<<temp->data<<" ";
  //   temp=temp->next; //getting the whole array printed!
  // }

  // cout<<lengthofLL(head);

  // cout<<search(head,2);

  // head=delete_head(head); 
  //head=removes_tail(head); 
  // print(head);

  
  return 0;
} 