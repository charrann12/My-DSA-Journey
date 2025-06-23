#include <bits/stdc++.h>
using namespace std;

int twoSum(int n,  vector<int> &arr, int target){
  sort(arr.begin(),arr.end());
  int left = 0;
  int right = n-1;
  
  while(left<right){
    int sum = arr[left] + arr[right];
    if(sum == target){
      return left,right;
    }
    else if(sum<target) left++;
    else right--;
    
  }
  
  return -1,-1;
  
}
int main() 
{
  int n = 5;
  vector<int>arr = {4,1,6,3,7};
  int target = 19;
  int ans  = twoSum(n,arr,target);
  cout<<ans<<endl;
    return 0;
}