/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
*/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n =nums.size();
        long long result =0 ;

        stack<int>st;
        for(int i =0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()]<nums[i])){
                int mid = st.top(); st.pop();
                int left = st.empty()?-1:st.top();
                int right  = i;
                result += (long long)(right - mid)*(mid - left)*nums[mid];
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()]>nums[i])){
                int mid = st.top(); st.pop();
                int left = st.empty()?-1:st.top();
                int right = i;
                result -=(long long)(right - mid)*(mid - left)*nums[mid];
            }
            st.push(i);
        }
        return result;
    }
};