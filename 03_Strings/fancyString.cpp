//problem : https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2025-07-21
//intuition : basic conditional statements and loops

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count = 1;

        for(int i =1;i<s.size();i++){
            if(s[i] == s[i-1]) count++;
            else count=1;

            if(count<3){
                ans+=s[i];
            }
        }
       return s.empty()?" ":s[0] + ans;
       

    }
    
};