class Solution {
public:
    string removeDigit(string number, char digit) {
        string maxResult = "";
        
        for(int i=0;i<number.length();i++){
            if(number[i]==digit){
                string candidate = number.substr(0,i)+number.substr(i+1);
                if(candidate>maxResult){
                    maxResult = candidate;
                }
            }
        }

        return maxResult;;
    }
};