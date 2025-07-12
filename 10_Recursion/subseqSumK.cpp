#include<bits.stdc++.h>
using namespace std;

void printS(int ind, vector<int>&ds, int s, int sum, vector<int>&nums,int n){
    if(ind == n){
        if(s == sum){
            for(auto :it){
                cout<< it<<" ";
                cout<<endl;
            }
            return;
        }
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    printS(ind +1, ds,s,sum,nums,n);
    ds.pop_back();
    s-=arr[ind];
    printS(ind+1,ds,s,sum,nums,n);
}

int main(){
    vector<int>nums = {1,2,1};
    int n = nums.size();
    int sum = 2;
    vector<int>ds;
    printS(0,ds,0,2,nums,n);
    return 0;
}