
/*
Given two integers L and R. Find the XOR of the elements in the range [L , R].


Examples:
Input : L = 3 , R = 5

Output : 2

Explanation : answer = (3 ^ 4 ^ 5) = 2.
*/
int XORUpto(int n){
  if(n%4==0) return n;
  else if(n%4==1) return 1;
  else if(n%4==2) return n+1;
  else return 0;
}

int findRangeXor(int l, int r){
  return XORUpto(r)^XORUpto(l-1);
}
