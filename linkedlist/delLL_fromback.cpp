#include <bits/stdc++.h>
using namespace std;
//Delete the nth node the back.
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
int lengthofLL(Node* head){
  int cnt=0;
  Node* temp = head;
  while(temp){
    temp=temp->next; 
    cnt++;
  }
  return cnt;
}

Node* del_brute(Node* head,int l){
    int k = lengthofLL(head);
    if(head==NULL) return head; 
    if(l==1){
        Node* temp = head;
        head= head->next;
        free(temp);
        return head; 
    }
    Node* temp = head;
    Node* prev=nullptr;//to make sure the all values are stored properly.
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-l+1){//here n(5)-l(2) is 3 but from back to remove second last element so +1!
            prev->next= prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* optimal(Node* head,int l){
    Node* slow = head;
    Node* fast = head;
    int cnt=0;
    while(cnt!=l){
        fast=fast->next;
        cnt++;//move fast till l times then if we move slow and fast simultaneously then while fast reach null slow's next will the lth node from back!
    }
    while(fast!=NULL && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    Node* temp = slow->next;
    slow->next=slow->next->next;
    free(temp);
    return head;
}

int main(){
    // int n;
    // cin>>n;
    // vector<int> arr(n);
    // for(int i=0 ; i<n ; i++){
    //   cin>>arr[i];
    // }
    vector<int> arr={1,3,5,2,5,8,7,10};
    int k;
    cin>>k;
    Node* head = convertarrToLL(arr);
    head = optimal(head,k);
    print(head);
}
