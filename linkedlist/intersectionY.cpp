//Question: Find the intersection point of the two given linked list!
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

void insertNode(Node* &head,int val) {
    Node* newNode = new Node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

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

Node* brute(Node* A,Node* B){
    while(A!=NULL){//making a constant - iterate through each of b if at some place it is equal to a then return else for next a->next go through the whole iteration of b again:
        Node* temp = B;
        while(temp!=NULL){
            if(temp==A) return A;
            temp=temp->next;
        }
        A=A->next;
    }
    return NULL;
}

Node* optimal(Node* headA,Node* headB){
    Node* A = headA;
    Node* B = headB;
    while(A!=B){
        if(A==NULL){ A=headB; }//move a till last when it reaches reassign it to the head of the other list head:
        else{ A=A->next; }//keep iterating:
        if(B==NULL){ B=headA; }
        else{ B=B->next; }
    }
    return A;

}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
    Node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    insertNode(headSec,3);
    Node* head2 = headSec;
    headSec->next = head;
    Node* ans = optimal(head1,head2);
    if(ans==NULL) cout<<"No intersection"<<endl;
    else cout<<ans->data;
    return 0;
} 