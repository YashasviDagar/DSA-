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

Node* delHead(Node* head){
    if( head == NULL || head->next==NULL){
        return NULL;
    }
    Node* prev = head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;//removing the link of first head towards the next list!
    delete prev;
    return head; 
}

Node* delTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;
    Node* current = temp->next;
    while(temp->next->next!=nullptr){
        temp=temp->next;
        current=current->next;
    }
    temp->next=nullptr;
    current->back=nullptr;
    delete current;
    return head;
}

Node* del_kth(Node* head,int k){
    if(head==NULL) return NULL;
    Node* temp = head;
    int cnt=0;
    while(temp !=NULL){
        cnt++;
        if(cnt==k) break;//standing behind the kth list!
        temp=temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev==NULL && front==NULL){
        return NULL;//just return null
    }else if(prev==NULL){
        return delHead(head);
    }else if(front==NULL){
        return delTail(head);
    }
    prev->next=front;//this skips the temp list and directly points prev to temps next!
    front->back=prev;//this skips the temp list and directly points front to temps back!
    temp->next=nullptr;//remove the 
    temp->back=nullptr;
    delete temp;
    return head;
}

void del_Node(Node* temp){
    //here k can't be head NEVER!
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
    }
    prev->next=front;
    front->back=prev;
    temp->next= temp->back=nullptr;
    free(temp);
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    // int k;
    // cin>>k;
  vector<int> arr = {1,3,5,6,7};
  Node* head = convertarr2DLL(arr);
//   head=del_kth(head,k);
//   print(head);
    del_Node(head->next->next);//here it wont ask to take head.. always the next numbers.
    print(head);
  return 0;
}