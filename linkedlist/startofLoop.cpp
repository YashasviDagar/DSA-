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

Node* brute(Node* head){
    Node* temp = head;
    unordered_map<Node*,int> mpp;
    while(temp!=NULL){
        if(mpp.count(temp)!=0){//either ues .find()!=end()
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return nullptr;//no loop
}

Node* optimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    int flag=1;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            flag=1;
            break;
        }else flag=0;
    }
    if(flag==1) slow=head; //for the no loop condition and returning null! removes run time error.
    else return nullptr;

    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    if(slow==fast) return fast;
    return nullptr;
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
    Node* checking=optimal(head); 
    if(checking) cout<<"found at "<<checking->data;//from here we got the value of the temp->data.. not in the function itself
    else cout<<"not found";
  return 0;
} 