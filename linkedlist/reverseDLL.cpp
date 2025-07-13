#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data = data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertarr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1 ; i<arr.size() ; i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;//prev->next=temp;
    }
    return head;
}
Node* brute(Node* head){
    Node* temp = head;
    stack<int> st;     //tc->O(2n) : sc->O(n)
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
Node* method(Node* head){
    Node* temp=head;
    Node* t = NULL;     //tc->O(n) : sc->O(1)
    while(temp!=NULL){
        t = temp->back;
        temp->back = temp->next;
        temp->next=t;
        temp=temp->back;
    }
    return t->back ;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
  vector<int> arr = {1,3,5,6,7};
  Node* head = convertarr2DLL(arr);
  head=method(head);
  print(head);
  return 0;
}