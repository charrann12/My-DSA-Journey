/*
Problem Statement: Given a doubly linked list of size ‘N’ consisting of positive integers, your task is to reverse it and return the head of the modified doubly linked list.


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

Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL){
        prev = curr->back;
        curr->back = curr->next;
        curr->next = prev;
        curr = curr->back;

    }
    return prev->back;

}