class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char ch: s){
            freq[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &entry: freq){
            pq.push({entry.second,entry.first});
        }

        string result = "";

        while(!pq.empty()){
            auto[count,ch] = pq.top();
            pq.pop();
            result.append(count,ch);
        }
        return result;
    }
};