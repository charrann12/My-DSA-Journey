#include <bits/stdc++.h>
using namespace std;

void longestSequence(vector<int> &arr){
  int n= arr.size();
  sort(arr.begin(),arr.end());
  int longest = 1;
  int current = 1;
  for(int i=1;i<n;i++){
    if(arr[i] == arr[i-1]) continue;
    if(arr[i]==arr[i-1]+1) current++;
  else{
    longest = max(longest,current);
    current = 1;
    
  }    
  }
longest = max(longest,current);
  cout<<longest;
}
int main() 
{
  vector<int> arr = {100,200,1,3,2,4};
  longestSequence(arr);
    return 0;
}