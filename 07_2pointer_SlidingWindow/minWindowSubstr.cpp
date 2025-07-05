/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.



*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int l=0,r=0,sIndex = -1;
        int minLen =INT_MAX;
        int cnt =0;
        vector<int>hash(256,0);
        for(int i=0;i<m;i++){
           hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0){
                cnt = cnt+1; 
            }
            hash[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) {
                cnt = cnt-1;
                }
                l++;
            }
            r++;
        }
        return sIndex == -1 ?"":s.substr(sIndex, minLen);
    }
};