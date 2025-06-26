/* RECURSIVE  APPROACH

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

*/

class Solution {
public:
    void generate(int open,int close,string current,vector<string>&result,int n){
        if(open == n && close ==n){
            result.push_back(current);
            return;
        }

        if(open<n){
            generate(open+1, close, current+"(", result, n);
        }

        if(close<open){
            generate(open, close+1, current+")", result, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(0,0,"",result,n);
        return result;
    }
};