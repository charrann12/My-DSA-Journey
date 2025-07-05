/* LEETCODE 1358. No of substrings with at most k characters.

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int>lastSeen(3,-1);
        int count =0;

        for(int i=0;i<n;++i){
            lastSeen[s[i] - 'a'] = i;
        

        if(lastSeen[0] != -1 && lastSeen[1]!= -1 && lastSeen[2] != -1){
            int minIndex= 1 +min({lastSeen[0], lastSeen[1], lastSeen[2]});
            count = count+minIndex;
        }
        }
        return count;
    }
};

/* traverse till you get a minimal substring of length 3 and if at all there exists any elements before the substring add their
count to total count  
nums = [a,a,b,a,c,a]
in this bac is the minimal subarray and there are 2 a's so count = count + substr fromed by abc + 2 a's substr

