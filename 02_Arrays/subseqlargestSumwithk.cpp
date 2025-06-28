/*
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
*/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>ind;
        for(int i=0;i<nums.size();i++){
            ind.push_back({nums[i],i});
        }

        sort(ind.begin(), ind.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });

        vector<pair<int, int>>topK(ind.begin(), ind.begin()+k);

        sort(topK.begin(), topK.end(),[](auto &a, auto&b){
            return a.second<b.second;
        });

        vector<int> result;
        for(auto &p: topK){
            result.push_back(p.first);
        }
        return result;
        
        
    }
};