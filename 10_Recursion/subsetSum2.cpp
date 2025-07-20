//problem: https://leetcode.com/problems/subsets-ii/description/
// take not take approach of recursion 

class Solution {
public:
    void subsetHelper(int ind, vector<vector<int>>&ans, vector<int>&nums, vector<int>&ds){
        ans.push_back(ds);
        
        for(int i = ind; i<nums.size(); i++){

            if(i>ind && nums[i] ==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subsetHelper(i+1, ans, nums, ds);
            ds.pop_back();
        }

}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        subsetHelper(0, ans, nums, ds);
        return ans;
    }
};