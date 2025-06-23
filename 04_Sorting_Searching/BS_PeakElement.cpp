#include <bits/stdc++.h>
using namespace std;
int peakElement(vector<int> &arr){
  int n = arr.size();
  if(n==1) return 0;
  if(arr[0]>arr[1]) return 0;
  if(arr[n-1]>arr[n-2]) return n-1;
  
  int low = 1,high = n-2;
  while(low<=high){
    int mid = (high + low)/2;
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
    if(arr[mid]>arr[mid-1]){
      //we are in the left
      low = mid+1; //eliminates left half
    }
    else{
      //we are in the right
      high = mid -1;//eliminates right half
    }
  }
  return -1;
}

int main() 
{
  vector<int> arr = {0,1,2,3,4,5,6,7,8};
  int ans = peakElement(arr);
  
    cout << ans;
    return 0;
}