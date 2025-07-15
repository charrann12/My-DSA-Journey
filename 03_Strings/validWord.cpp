// problem: https://leetcode.com/problems/valid-word/description/?envType=daily-question&envId=2025-07-15
// intuition : ifelse statements

class Solution {
public:
    bool isValid(string word) {
        int vowel = 0;
        int consonent = 0;
        int notSymbol = 0;
        if(word.length()<=2) return false;
        for(int i =0;i<word.length(); i++){
            word[i] = tolower(word[i]);
        }
        for(char letter : word){
            if(letter >='a' && letter <= 'z'){
                notSymbol++;
            if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter== 'u' ){
                vowel++;
            }
            else{
                consonent++;
            }
            }

            else if(letter-'0' <= 9 && letter-'0' >=0){
                notSymbol++;
            }

        }
        if(vowel && consonent && notSymbol == word.length()) return true;
        else
        return false;

    }
};