//Question: Check whether a given linked list is a palindrome list or not?

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

Node* reverse_recursive(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* newHead=reverse_recursive(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
    /*
    ~So here, i understand that new node will be the last element of this LL.
    ~Now front is head's next in this case 3. now since front is 3 and its basically last element its next element will be second last element which is head itself so make front's next to head. 
    ~Then just point head to NULL itself.
    */
}

bool brute_force(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=st.top()) return false;
        st.pop();
        temp=temp->next;
    }
    return true;
}

bool isPalin(Node* head){
    if(head==NULL || head->next==NULL) return true;
    Node* slow = head;
    Node* fast =  head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){// not || 
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead = reverse_recursive(slow->next);
    //make newHead so that the list is divided into two and so that we can iterate linearly!
    Node* first = head;
    Node* second = newHead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverse_recursive(newHead);//cuz we cant change the original list therfore reverse the reversed list before returning any value;
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse_recursive(newHead);//converted to original list
    return true;

}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
  vector<int> arr={1,2,3,3,2,1};
  Node* head = convertarrToLL(arr);

  if(isPalin(head)) cout<<"True";
  else cout<<"False";

  
  return 0;
} 