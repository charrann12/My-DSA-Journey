#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  
  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }
  
  public:
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};

// array to linked list 
Node* convertArr2ll(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    
  Node* temp = new Node(arr[i]);
  mover->next = temp;
  mover = temp;
}
return head;
}

// length of linked list
int lengthofll(Node* head){
  int count = 0;
  Node* temp = head;
  
  while(temp){
    temp = temp->next;
    count++;
  }
  return count;
}

// check if node present
int checkIfPresent(Node* head, int val){
  Node* temp = head;
  while(temp){
    if(temp->data == val) return 1;
    temp = temp->next;
  }
  return 0;
}


// deletion

//delete head
Node* removeHead(Node* head){
  if(head==NULL) return head;
  Node* temp = head;
  head = head->next;
  delete temp;
  return head;
}

//print function
void print(Node* head){
  while(head!= NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}


//delete tail
Node* removeTail(Node* head){
  if(head==NULL || head->next==NULL) return head;
  Node* temp = head;
  while(temp->next->next!=NULL){
   temp = temp->next;
  }
  free(temp->next);
  temp->next = nullptr;
 return head;
}

// delete k index node
Node* removeK(Node* head,int k){
  if(head == NULL) return head;
  if(k==1){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  int cnt = 0;
  Node* temp = head;
  Node * prev = NULL;
  while(temp!=NULL){
    cnt++;
    if(cnt==k){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}


//delete node
Node* removeValue(Node* head, int value){
  if(head == NULL) return head;
  if(head->data == value){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  
  Node* temp = head;
  Node* prev = NULL;
  while(temp!=NULL){
    if(temp->data == value){
      prev->next = prev->next->next;
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
  
}


// insertion 

//at head
Node* insertHead(Node* head, int val){
  Node* temp = new Node(val,head);
  return temp;
}

//at tail
Node* insertTail(Node* head, int val){
  if(head == NULL){
    return new Node(val);
  }
  Node* temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  Node* newNode = new Node(val);
  temp->next = newNode;
return head;
}

// insert at position 
Node* insertPosition(Node* head, int el,int k){
  if(head == NULL){
    if(k==1){
      return new Node(el);
    }
  }
  if(k==1){
    Node* newHead = new Node(el,head);
    return newHead;
  }
  
  int cnt = 0;
  Node* temp = head;
  while(temp!=NULL){
    cnt++;
    if(cnt == k-1){
      Node* x = new Node(el, temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}


// insert before value

Node* insertBeforevalue(Node* head, int el, int val){
  if(head == NULL) return NULL;
  if(head->data == val){
    return new Node(el,head);
  }
  Node* temp = head;
  while(temp!=NULL){
    if(temp->next->data == val){
      Node* x = new Node (el,temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}

int main() 
{
  vector<int> arr = {12,5,3,8};
  Node* head = convertArr2ll(arr);
  head = insertBeforevalue(head,100,12);
  print(head);
    return 0;
}