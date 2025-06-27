/* SUBSETS

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int num = 0;num<(1<<n);num++){
            vector<int>sub;
            for(int i=0;i<n;i++){
                if(num&(1<<i)){
                    sub.push_back(nums[i]);
                }
            }
                        ans.push_back(sub);
    }
    return ans;
    }
};