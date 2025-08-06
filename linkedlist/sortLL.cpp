//Question: According to the data sort the linked list.
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
    multiset<int> ms;
    Node* temp = head;
    while(temp!=NULL){
        ms.insert(temp->data);
        temp=temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data=*ms.begin();//use star to access the begin():
        ms.erase(ms.begin());
        temp=temp->next;
    }
    return head;
}

Node* mergeTwoLL(Node* list1,Node* list2){
    // Create a dummy node to serve as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer to the next node
        temp = temp->next; 
    }

    // If any list still has remaining elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}


Node* findmid(Node* head){
    Node* temp = head;
    Node* slow = head;
    Node* fast = head->next;//this returns the first middle in case of even number of list: In prev faast pointed to head only!
    while(fast!=nullptr && fast->next!=nullptr){
        slow=temp->next;
        fast=temp->next->next;
        temp=temp->next;
    }
    return slow;
}

Node* sortLL(Node* head){//tc->O(Nlog(N)) sc->O(1)
    if(head==NULL || head->next==nullptr) return head;
    Node* mid = findmid(head);
    Node* lefthead = head;
    Node* righthead = mid->next;
    mid->next=nullptr;
    lefthead=sortLL(lefthead);
    righthead=sortLL(righthead);
    return mergeTwoLL(lefthead,righthead);
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
int main(){
  vector<int> arr={1,3,5,2,7,5,6,7};
  Node* head = convertarrToLL(arr);
  head=sortLL(head);
  print(head);
  return 0;
} 