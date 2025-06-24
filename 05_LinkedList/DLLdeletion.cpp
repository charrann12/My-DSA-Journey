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

// deletion
//head
Node* deletehead(Node* head){
  if(head == NULL || head->next == NULL){
    return NULL;
  }
  Node* temp = head;
  head = head->next;
  head->back = nullptr;
  temp->next = nullptr;
  delete temp;
  return head;
}

//tail
Node* deleteTail(Node* head){
  if(head==NULL || head->next == NULL) return NULL;
  Node* temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  Node* prev = temp->back;
  prev->next = nullptr;
  temp->back = nullptr;
  delete temp;
  return head;
}

//kth index
Node* deleteKthIndex(Node* head, int k){
  if(head == NULL ) return NULL;
  
  int cnt = 0;
  Node* kNode = head;
  while(kNode!=NULL){
    cnt++;
    if(cnt==k) break;
    kNode = kNode->next;
  }
  
  Node* prev = kNode->back;
  Node* front = kNode->next;
  
  if(prev == nullptr && front == nullptr){
    delete(kNode);
    return NULL;
  }
  
  else if(prev==NULL){
    return deletehead(head);
  }
  
  else if(front == NULL){
    return deleteTail(head);
  }
  else{
    prev->next = front;
    kNode->next = nullptr;
    front->back = prev;
    kNode->back = nullptr;
    delete kNode;
    return head;
  }
}

void deleteNode(Node* temp){
  Node* prev = temp->back;
  Node* front = temp->next;
  
  if(front == NULL){
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return;
  }
  
  prev->next  = front;
  front->back = prev;
  
  temp->back = temp->next = nullptr;
  free(temp);
  
}
int main() 
{
  vector<int> arr = {12,5,1,7};
  Node* head = convertDll2Arr(arr);
  deleteNode(head->next->next);
  print(head);
    return 0;
}