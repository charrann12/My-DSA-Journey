//problem: https://leetcode.com/problems/subsets/description/
// approach: recursion with backtracing 
// take not take method




class Solution {
public:

    void generateSubstrs(int ind, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i = ind;i<nums.size();i++){
            curr.push_back(nums[i]);
            generateSubstrs(i+1, nums, curr, ans);

            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        generateSubstrs(0, nums, curr, ans);

        return ans;


    }
};