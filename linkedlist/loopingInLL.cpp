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

bool hashing(Node* head){
    Node* temp = head;
    map<Node*,int> mpp;
    while(temp!=NULL){//this for in case of linear.
        if(mpp.find(temp)!=mpp.end()){//here find returns a iterator to the given key which is checked so if not present it returns the end() value:
            return true;
        }
        mpp[temp]==1;
        temp=temp->next;
    }
    return false;
}

bool torAndhare(Node* head){
    
    Node* slow = head;
    Node* fast = head; //tc-> tending to O(n) sc->O(1)
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast) return true;
    }
    return false;
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
//   vector<int> arr={1,3,5,2,10,3};
//   Node* head = convertarrToLL(arr);
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

    if(torAndhare(head)){
        cout<<"TRUE";
    }else cout<<"FALSE";

  return 0;
} 