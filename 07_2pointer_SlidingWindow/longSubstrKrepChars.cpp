/* LEETCODE 395
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s,0,s.size(),k);
    }

    int helper(string &s, int start, int end,int k){
        if(end-start < k) return 0;

        vector<int> freq(26,0);
        for(int i =start;i<end;i++){
            freq[s[i] -'a']++;
        } 

        for(int i=start;i<end;i++){
            if(freq[s[i]-'a']<k){
                int j = i+1;
                while(j< end && freq[s[j]-'a']<k) j++;
                return max(helper(s,start,i,k), helper(s,j,end,k));
            }
        }
        return end - start;
    }
};