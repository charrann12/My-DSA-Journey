#include <iostream>
using namespace std;

void rec_insertion_sort(int arr[], int i,int n){
  if(i==n) return ;
  int j=i;
  while(j>0 && arr[j-1]>arr[j]){
    int temp = arr[j-1];
    arr[j-1] = arr[j];
    arr[j] = temp;
    j--;
    }
    rec_insertion_sort(arr,i+1,n);
}
int main() 
{
  int arr[] = {9,1,0,4,8,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  rec_insertion_sort(arr,0,n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
    return 0;
}