#include <iostream>
using namespace std;

void palindrome(int n){
  int original = n;
  int rev = 0;
  while(n>0){
    int ld = n%10;
    rev = (rev*10) + ld;
    n = (n/10);
  }
  if(rev == original)
    cout<<"its a palindrome"<<endl;
    else
    cout<<"not a palindrome";
}
int main(){
    int n;
    cin>>n;
    palindrome(n);
   
    return 0;
}
