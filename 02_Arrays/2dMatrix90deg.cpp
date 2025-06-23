#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>>&Matrix){
  int n = Matrix.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      swap(Matrix[i][j],Matrix[j][i]);
    }
  }
  
  for(int i=0;i<n;i++){
    reverse(Matrix[i].begin(),Matrix[i].end());
  }
}
int main() 
{
  vector<vector<int>> Matrix = {{1,2,3},{4,5,6},{7,8,9}};
  rotateMatrix(Matrix);
  for(int i=0;i<Matrix.size();i++){
    for(int j=0;j<Matrix[0].size();j++){
      cout<<Matrix[i][j]<< " ";
    }
    cout<<endl;
  }
    return 0;
}