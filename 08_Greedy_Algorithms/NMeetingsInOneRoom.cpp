N Meetings in One Room 

#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

class Solution{
    public: 
    bool static comp(struct meeting m1, meeting m2){
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos) return true;
        return false;
    }

    vector<int> maxMeetings(int s[], int e[], int n){
        struct meeting meet[n];
        for(int i =0;i<n;i++){
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i+1;
        }

        sort(meet, meet+n, comp);

        vector<int> ans;
        int limit = meet[0].end;
        ans.push_back(meet[0].pos);

        for(int i =1;i<n;i++){
            if(meet[i].start > limit){
                ans.push_back(meet[i].pos);
                limit = meet[i].end;
            }
        }
        return ans;
    }

};