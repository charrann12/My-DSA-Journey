#include<bits.stdc++.h>
using namespace std;

int printS(int ind, int s, int sum, vector<int>&nums,int n){
    if(ind == n){
        // condition satisfied
        if(s == sum)return 1;

        //condition not satisfied
        else return 0;
        
    }

    s+=arr[ind];
    int l = printS(ind +1,s,sum,nums,n);
    
    s-=arr[ind];
    printS(ind+1,s,sum,nums,n);

    return l+r;
}

int main(){
    vector<int>nums = {1,2,1};
    int n = nums.size();
    int sum = 2;
    printS(0,0,2,nums,n);
    return 0;
}