//Question: Sort a LL of 0's 1's 2's in certain manner!
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

Node* sorting(Node* head){
  if(head==NULL || head->next==NULL) return head;
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroTail->next=temp;
            zeroTail=zeroTail->next;
        }else if(temp->data==1){
            oneTail->next=temp;
            oneTail=oneTail->next;
        }else{
            twoTail->next=temp;
            twoTail=twoTail->next;
        }
        temp=temp->next;
    }
    if(oneHead->next!=NULL){//if no 1 present!
        zeroTail->next=oneHead->next;
    }else zeroTail->next=twoHead->next;

    if(oneHead->next!=NULL && twoHead->next!=NULL){//if no 1 and 2 present!
        zeroTail->next=oneHead->next;
    }else zeroTail->next=NULL;

    if(twoHead->next!=NULL){//if no 2 present
        oneTail->next=twoHead->next;
    }else oneTail->next=NULL;
    
    twoTail->next=NULL;
    return zeroHead->next;
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
  vector<int> arr={1,2,2,1,2,0,2,2};
  Node* head = convertarrToLL(arr);
  head=sorting(head);
  print(head);
  return 0;
} 