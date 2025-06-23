#include <iostream>
using namespace std;

void selection_sort(int arr[],int n){
  for(int i=0;i<n;i++){
    int mini = i;
    for(int j=i+1;j<n;j++){
      if(arr[mini]>arr[j])
      mini = j;
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
  
  cout<<"after selection_sort the order will be :";
  for(int i =0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}

int main() 
{
  int arr[] = {3,10,0,9,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  
    selection_sort(arr,n);
    return 0;
}