/* LEETCODE 1876

A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int l=0,r=0,count =0;
        map<char, int>mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>1 || mpp.size()>3){
                if(--mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(r-l+1 == 3){
                count++;
            }
            
            r++;
        }
        return count;
    }
};