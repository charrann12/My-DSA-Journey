/* 85. MAXIMAL RECTANGLE
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
*/

class Solution {
public:

    int largestRectangleArea(vector<int>&arr){
        stack<int>st;
        int n = arr.size();
        int maxArea = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
               int index = st.top(); st.pop();
               int nse = i;
               int pse = st.empty()?-1:st.top();
                maxArea = max(maxArea, arr[index]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
           int  nse = n;
            int index = st.top(); st.pop();
            int pse = st.empty()? -1: st.top();
             maxArea = max(maxArea, arr[index]*(nse-pse-1));

        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxRect = 0;
        vector<int>heights(m, 0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                heights[j] = (matrix[i][j]=='1')?heights[j]+1:0;
            }
            maxRect = max(maxRect, largestRectangleArea(heights));
        }
        return maxRect;
    }
};