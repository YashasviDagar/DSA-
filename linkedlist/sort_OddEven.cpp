#include <bits/stdc++.h>
using namespace std;
//Question: Sort the odd and even linked list in such a manner that the odd place list comes before even place list
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

Node* brute(Node* head){//tc->(2N) sc->O(N)
    if(head==NULL && head->next==nullptr);
    Node* temp = head;
    vector<int> arr;
    while(temp!=NULL && temp->next!=nullptr){//tc->O(N/2)
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);//this bcz in while if odd ll then last element might not be added in the array!
    temp=head->next;
    while(temp!=NULL && temp->next!=nullptr){//tc->O(N/2)
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);//this bcz in while if odd ll then last element might not be added in the array!
    temp=head;
    int i=0;
    while(temp!=NULL){//tc->O(N)
        temp->data=arr[i++];
        temp=temp->next;
    }
    return head;
}

Node* optimal(Node* head){//tc->O((n/2)*2) as we change the odd and even links simultaneously. sc->O(1)
    if(head==NULL && head->next==nullptr);
    Node* odd = head;
    Node* even = head->next;
    Node* headOFEven = head->next;
    while(even!=NULL && even->next!=nullptr){//odd length works as when the last step for odd takes place even will take place and then the even head to directly point towards the NULL.
        odd->next=odd->next->next;
        even->next=even->next->next;
        //odd->next is changed. so odd moves two places in the list!
        odd=odd->next;
        even=even->next;
    }
    odd->next=headOFEven;//preserved the start of even head so that odd last list can point to the head_even start.
    return head;
    
}

int main(){
    // int n;
    // cin>>n;
    // vector<int> arr(n);
    // for(int i=0 ; i<n ; i++){
    //   cin>>arr[i];
    // }
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    
    Node* head = convertarrToLL(arr);
    head = optimal(head);
    print(head);
}
