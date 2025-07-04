/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


approach:
even when we increment the r and odds dont change the substr is getting added up into the count.
So as per the binary subarray with sum we will find of odds<=k and subtract with odds<= goal -1 
*/


class Solution {
public:

int firstfunc(vector<int>&nums,int k){
    int l=0,r=0,cnt=0, odds=0;
    while(r<nums.size()){
        if(nums[r]%2 != 0) odds++;
        while(odds>k){
            if(nums[l]%2 != 0) odds--;
            l++;
        }
        cnt = cnt +(r-l+1);
        r++;
    }
    return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return firstfunc(nums,k) - firstfunc(nums,k-1);
    }
};