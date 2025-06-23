#include <bits/stdc++.h>
using namespace std;

string result (string s){
  int left = 0, right = s.length()-1;
  string temp="";
  string ans = "";
  
  while(left<=right){
    char ch = s[left];
    if(ch!=' '){
      temp+=ch;
    }
    else if(ch==' '){
      if(ans!="") ans = temp + ' ' +ans;
      else ans = temp;
      temp = "";
    }
    left++;
  }
  if(temp!=""){
    if(ans!="") ans = temp + " " + ans;
    else ans = temp;
  }
  return ans;
}
int main() 
{
  string s = "this is an amazing program";
  string reverse = result(s);
  
    cout << reverse;
    return 0;
}