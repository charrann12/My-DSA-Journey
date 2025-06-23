#include <iostream>
using namespace std;
void rec_bubble_sort(int arr[], int n){
  if(n==1) return;
  for(int j=0;j<=n-2;j++){
    if(arr[j]>arr[j+1]){
      int temp = arr[j+1];
      arr[j+1] = arr[j];
      arr[j] = temp;
    }
  }
  
  rec_bubble_sort(arr,n-1);
}
int main() 
{
    int arr[] = {9,1,6,2,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    rec_bubble_sort(arr,n);
    cout<<"the sorted array is :";
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }    
    return 0;

}