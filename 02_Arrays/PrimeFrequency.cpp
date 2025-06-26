/*3591. Check if Any Element Has Prime Frequency

You are given an integer array nums.

Return true if the frequency of any element of the array is prime, otherwise, return false.

The frequency of an element x is the number of times it occurs in the array.

A prime number is a natural number greater than 1 with only two factors, 1 and itself.

 

Example 1:

Input: nums = [1,2,3,4,5,4]

Output: true

Explanation:

4 has a frequency of two, which is a prime number.

*/

class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        for(int i=2;i<=sqrt(n);++i){
            if(n%i == 0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
    unordered_map<int, int> freq;

        for(int num: nums){
            freq[num]++;
        }

        for(auto& pair : freq){
            if(isPrime(pair.second))
                return true;
        }
        return false;
        
    }
};