#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n){
  int low = 0,mid = 0,high = n-1;
  while(mid<=high){
    if(arr[mid]==0){
      swap(arr[mid],arr[low]);
      mid++;
      low++;
    }
    else if (arr[mid]==1){
      mid++;
    }
    else if(arr[mid]==2){
      swap(arr[mid],arr[high]);
      high--;
    }
  }
}
int main() 
{
  vector<int> arr = {2,0,1,1,0,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  sortArray(arr,n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<",";
  }
  
    return 0;
}