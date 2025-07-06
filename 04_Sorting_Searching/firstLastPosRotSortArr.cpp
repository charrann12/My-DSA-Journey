/* LEETCODE 34
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/

class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
    int first = findFirst(nums,target);
    int last = findLast(nums, target);
    return{first,last};
}
    int findFirst(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0,high = n-1;
        int res = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                res = mid;
                high = mid -1;
            }
            else if(nums[mid] >target){
                high = mid -1;
            }
            else{
                low = mid+1;
            }

        }
        return res;
    }
    int findLast(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0,high = n-1;
        int res = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                res = mid;
                low = mid +1;
            }
            else if(nums[mid] >target){
                high = mid -1;
            }
            else{
                low = mid+1;
            }

        }
        return res;
    }
};