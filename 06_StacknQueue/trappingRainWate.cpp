/* TRAPPING RAIN WATER
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int lMax = 0, rMax = 0,total = 0;
        int l =0,r = n-1;

        while(l<r){
            if(arr[l]<arr[r]){
             if(lMax>arr[l]){
                total +=lMax-arr[l];
             }
             else{
                lMax = arr[l];
             }
             l = l+1;
            }
            else{
                if(rMax>arr[r]){
                    total+=rMax-arr[r];
                }
                else{
                    rMax = arr[r];
                }
                r=r-1;
            }
        }
        return total;
    }
};