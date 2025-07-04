/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/

// our approach here will be to write a function in which substr cnt  <= goal and subtract those from substr cnt <= goal 1
// eventually that gives answer for substr cnt = goal

class Solution {
public:
int firstfunc(vector<int>&nums, int goal ){
    if(goal<0) return 0;
    int l=0,r=0,sum=0,cnt =0;
    while(r<nums.size()){
        sum+= nums[r];
        while(sum>goal){
            sum = sum - nums[l];
            l = l+1;
        }
        cnt = cnt +(r-l+1);
        r = r+1;
    }
    return cnt;
}

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return firstfunc(nums,goal) - firstfunc(nums,goal-1);
}
    
};