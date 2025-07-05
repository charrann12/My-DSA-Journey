/*
Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 

Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:

The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
Example 2:

Input: s = "aaaa"

Output: 2

Explanation:

The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".

*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,r=0,maxlen = 0;
        int n = s.length();
        vector<int>hash(26,0);

        while(r<n){
            hash[s[r]-'a']++;
            while(hash[s[r]-'a'] >2){
                hash[s[l]-'a']--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};