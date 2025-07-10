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
void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
Node* inserthead(Node* head,int val){
    Node* temp = new Node(val,head);
    return temp;//return new Node(val,head)
}
Node* insertTail(Node* head, int val){
    if(head==NULL) return new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next=newNode;
    return head;

}
Node* insert_kth(Node* head, int k,int val){
    if(head==NULL){
        if(k==1) return new Node(val);//tc-> O(N)  This is valid — you're basically creating a new list with one node.
        else return NULL;//k>1,That's invalid, because there's no node at position k-1 to insert after.
    }
    if(k==1){
        Node* temp = new Node(val,head);
        return temp;//non empty list then trying to update the head!
    }
    Node* temp = head;
    int cnt=0;
    while(temp!=nullptr){//travel through whole LL
        cnt++;
        if(cnt==k-1){//k-1 bcz we insert at kth place so iterate till k-1
            Node* newNode = new Node(val,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node* insertBeforevalue(Node* head,int el,int val){
    if(head==NULL) return NULL;//here val is already present in the LL
    if(head->data==val) return new Node(el,head);
    Node* temp = head;         //and el is the element to be inserted!
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* newNode = new Node(el,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    int val,k;
    cin>>val>>k;
    vector<int> arr={1,2,5,8,10};
    Node* head = convertarrToLL(arr);
    head = insertBeforevalue(head,val,k);
    print(head);
    return 0;
}