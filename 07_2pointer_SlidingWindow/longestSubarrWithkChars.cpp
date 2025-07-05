/*
This is a problem for counting the longest substring with atmost k characters 
*/



int longestSubArray(string s, int k){
    int maxlen =0, l =0, r=0;
    map<char, int>mpp;
    while(r<s.size()){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] ==0) mpp.erase(s[l]);
            l++;
        }
        if(mpp.size()<=k){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}