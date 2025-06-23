#include <bits/stdc++.h>
using namespace std;

vector<int> leader(vector<int> &arr){
  int n = arr.size();
  vector<int> ans;
 int max = arr[n-1];
 ans.push_back(arr[n-1]);
 for(int i=n-2;i>=0;i--){
   if(arr[i]>max) {
     ans.push_back(arr[i]);
     max = arr[i];
 }
 }
return ans;
}
int main() 
{
  vector<int> arr = {4,10,7,6};
  vector<int> elements = leader(arr);
  for (int i=elements.size()-1;i>=0;i--){
    cout<<elements[i]<<" ";
    }
    return 0;
}