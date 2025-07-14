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
    stack<int> st;     
    while (temp != nullptr) {
        st.push(temp->data); 
        temp = temp->next;    
    }
    temp = head; 
    while (temp != nullptr) {
        temp->data = st.top();  
        st.pop();              
        temp = temp->next;     
    }
    return head;  
}

Node* iterative(Node* head){
    if(head==NULL || head->next==nullptr) return head;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=NULL){
        Node* front = temp->next;//this is changing of the node pointer's! basically swap!
        temp->next=prev;

        prev=temp;//this is for moving to the next node to again perform the task!
        temp=front;
    }
    return prev;
}

Node* recursive(Node* head){
    if(head==NULL || head->next==NULL) return head;
    
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
  vector<int> arr={1,3,5,2,10};
  Node* head = convertarrToLL(arr);
  head=iterative(head);
  print(head);
  return 0;
} 