
#include <bits/stdc++.h>

using namespace std;
int Stocks(vector<int> &a){
  int n = a.size();
  int minPrice = INT_MAX;
  int maxPro = 0;
  for(int i=0;i<n;i++){
    minPrice = min(minPrice,a[i]);
    maxPro = max(maxPro, a[i] - minPrice);
  }
  return maxPro;
}
int main() 
{
  vector<int> arr = {7,6,4,2,1};
  int ans = Stocks(arr);
  cout<<ans;
    return 0;
}