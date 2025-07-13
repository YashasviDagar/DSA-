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

Node* naive(Node* head){
    Node* temp=head;
    int cnt=0;
    //tc->O(n+n/2)
    while(temp!=0){
        cnt++;
        temp=temp->next;
    }
    int middle=((cnt)/2+1);
    temp=head;
    while(temp!=0){
        middle--;
        if(middle==0) break;
        temp=temp->next;
        
    }
    return temp;
}

Node* tortoiseHare(Node* head){
    Node* temp = head;//tc->O(n/2) : sc->O(1)
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=temp->next;
        fast=temp->next->next;
        temp=temp->next;
    }
    return slow;
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
  vector<int> arr={1,3,5,2,10};
  Node* head = convertarrToLL(arr);
  head=tortoiseHare(head);
  print(head);
  return 0;
} 