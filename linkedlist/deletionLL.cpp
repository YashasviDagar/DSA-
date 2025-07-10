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
Node* remove_kthele(Node* head,int k){//O(K)
    if(head==NULL) return head; //empty list
    if(k==1){
        Node* temp = head;
        head= head->next;//this makes the head point to the next element in the list.
        free(temp);
        return head; //this is a whole new or main function therefore return
    }
    Node* temp = head;
    Node* prev=nullptr;//to makw sure the all values are stored properly.
    int cnt=0;//here we will increase the cnt as first step in while loop.
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next= prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* remove_value(Node* head,int k){//O(K)
    if(head==NULL) return head; //empty list
    if(head->data==k){
        Node* temp = head;
        head= head->next;//this makes the head point to the next element in the list.
        free(temp);
        return head; //this is a whole new or main function therefore return
    }
    Node* temp = head;
    Node* prev=nullptr;//to makw sure the all values are stored properly.
    while(temp!=NULL){
        if(temp->data==k){
            prev->next= prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main(){
    int k;
    cin>>k;
    vector<int> arr={1,3,5,2,5,8,7,10};
    Node* head = convertarrToLL(arr);
    head = remove_value(head,k);
    print(head);
  return 0;
}