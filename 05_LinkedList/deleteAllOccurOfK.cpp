/*

delete all occurences of element k in a doubly linked list 

*/


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

Node* deleteOccurencesOfK(Node* head, int target){
    Node* curr  = head;
    while(curr!=nullptr){
        if(curr->data == target){
            Node* toDelete = curr;
            if(curr->back) curr->back->next = curr->next;
            else head = curr->next;

            if(curr->next) curr->next->back = curr->back;
            curr = curr->next;
            delete toDelete;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}