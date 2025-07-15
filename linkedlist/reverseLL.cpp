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
    Node* newHead=recursive(head->next);
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

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
  vector<int> arr={1,3,5,2};
  Node* head = convertarrToLL(arr);
  head=recursive(head);
  print(head);
  return 0;
} 