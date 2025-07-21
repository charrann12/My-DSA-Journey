//problem: https://leetcode.com/problems/happy-number/description/
//intuition: if squaring the digits and summing them up reaches 1 its a happy number else it is not

class Solution {
public:
int helperFunction(int n){
    int temp = n;
    int ans = 0;
    while(temp>0){
    int digit = temp%10;
    ans +=(digit*digit);
    temp/=10;
    }
    return ans;
}
    bool isHappy(int n) {
        int result = n;
        if (result == 1) return true;
        else if (result==4) return false;
        while(result!=1 && result!=4){
            result = helperFunction(result);
        }
        return result==1;
    }

};

