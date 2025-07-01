/* LARGEST RECTANGLE IN A HISTOGRAM 
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Input: heights = [2,4]
Output: 4

intuition :
stack must store indexes. 
until u get a smaller element than the stack top push the index. 
once u get the value of the index will be the next smaller element of the stack top. and initialise the stack top to some element and pop it out. 
the new stack top will be previous small element. 
to get the area arr[i]*(nse - pse - 1);
after the complete iteration if we are still left with index values in the stack and there arent any of the pse or nse let pse be -1(in case of stack empty) and nse be the size of the array. and then calculate the area with the same prev formula

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int maxArea = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxArea = max(maxArea, heights[element]*(nse-pse-1)); 
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element  = st.top(); st.pop();
           int  pse = st.empty()?-1:st.top();
            maxArea = max(maxArea, heights[element] *(nse-pse-1));
        }
        return maxArea;
    }
};