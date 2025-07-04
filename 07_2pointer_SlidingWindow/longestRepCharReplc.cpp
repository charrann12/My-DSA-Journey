/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

*/

//Optimal approch 1 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxLen =0, maxFre = 0;
        vector<int>hash(26,0);

        while(r<s.length()){                                    //O(N)
            hash[s[r]-'A']++;
            maxFre = max(maxFre, hash[s[r]-'A']);

            while((r-l+1) - maxFre > k){                        //O(N)
                hash[s[l]-'A']--;
                maxFre = 0;
                for(int i=0;i<26;i++){                          //O(26)
                    maxFre = max(maxFre, hash[i]);
                }
                l = l+1;
            }

            if((r-l+1) - maxFre <= k){                      // total time complexity is O(2N)
                maxLen = max(maxLen, r-l+1);                // space complexity is O(26)
            }

            r++;
        }

        return maxLen;
    }
    
};

// Optimal method 2

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxLen =0, maxFre = 0;
        vector<int>hash(26,0);

        while(r<s.length()){
            hash[s[r]-'A']++;
            maxFre = max(maxFre, hash[s[r]-'A']);

            if((r-l+1) - maxFre > k){               // while -> if // total time complexity reduced to O(N + 1) 
                hash[s[l]-'A']--;
                /*maxFre = 0;
                for(int i=0;i<26;i++){
                    maxFre = max(maxFre, hash[i]);  // removing the freq check rather let the maxFre remain same and adjust the window size accordingly
                }
                */
                l = l+1;
            }

            if((r-l+1) - maxFre <= k){
                maxLen = max(maxLen, r-l+1);
            }

            r++;
        }

        return maxLen;
    }
    
};