#include <bits/stdc++.h>
using namespace std;
int majorelement(vector<int> &v){
  int n = v.size();
  int cnt = 0;
  int el;
  for(int i=0;i<n;i++){
    if(cnt==0){
      cnt++;
      el=v[i];
    }
    else if (el == v[i]) cnt++;
    else cnt--;
  }
  
  int cnt1=0;
  for(int i=0;i<n;i++){
    if(v[i]==el) cnt1++;
  }
  if(cnt1>(n/2)) return el;
    return -1;
}
int main() 
{
  vector<int> arr = {1,2,2,2,1,2,2,2};
  int ans  = majorelement(arr);
  
    cout << ans;
    return 0;
}