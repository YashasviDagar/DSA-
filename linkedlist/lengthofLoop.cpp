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

int looplength(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=nullptr){
        
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    slow=slow->next;
    int cnt=0;
    while(slow!=fast){
        slow=slow->next;
        cnt++;
    }
    return cnt+1;
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;
    int len = looplength(head);
    cout<<len; 
  return 0;
} 