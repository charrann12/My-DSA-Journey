class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    
        vector<string> result;
        for(int i=0;i<s.length();i+=k){
            string part = s.substr(i,k);
            if(part.length()<k){
                part += string(k-part.length(), fill);
            }
            result.push_back(part);
        }
return result;

    }
};