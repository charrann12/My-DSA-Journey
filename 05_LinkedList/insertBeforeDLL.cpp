#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* back;
  
  public:
  Node(int data1, Node* next1, Node* back1){
    data = data1;
    next = next1;
    back = back1;
  }
  
  public:
  
  Node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};


Node* convertDll2Arr (vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* prev = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i],nullptr,nullptr);
    prev->next = temp;
    temp->back = prev;
    prev = prev->next;
  }
  return head;
}


void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
}

//insertion
//before
//head-

Node* insertHead(Node* head, int val){
  if(head==NULL){
    return new Node(val);
  }
  Node* newNode = new Node(val, head, nullptr);
  head->back = newNode;
  return newNode;
}

//tail
Node* insertAtTail(Node* head, int val){
  if(head==NULL){
    return NULL;
  }
  else if(head->next == NULL){
    return insertHead(head,val);
  }
  
  Node* tail = head;
  
  while(tail->next!=NULL){
    tail = tail->next;
  }
  Node* tailFront = tail->back;
 Node* newNode = new Node(val);
 tailFront->next = newNode;
 newNode->back = tailFront;
 
 tail->back = newNode;
 newNode->next = tail;
 
 return head;
}

// before kth index

Node* insertBeforeKth(Node* head,int val,int k){
  if(head == NULL) return NULL;
  int cnt = 0;
  Node* kNode = head;
  while(kNode!=NULL){
    cnt++;
    if(cnt == k) break;
    kNode = kNode->next;
  }
  
  Node* prev = kNode->back;
  Node* newNode = new Node(val,kNode,prev);
  prev->next = newNode;
  kNode->back = newNode;
  
  return head;
}

// before Node
void insertNode(Node* node,int val ){
  Node* prev = node->back;
  Node* newNode = new Node(val,node,prev);
  prev->next = newNode;
  node->back = newNode;
  
}
int main() 
{
    vector<int> arr = {12,5,1,7};
  Node* head = convertDll2Arr(arr);
  insertNode(head->next->next,9);
  print(head);
    return 0;
}