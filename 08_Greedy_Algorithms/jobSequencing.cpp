/*
Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

Examples

Example 1:

Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}

Output: 2 60

Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
Profit = 40 + 20 = 60

Example 2:

Input: N = 5, Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}

Output: 2 127

Explanation: The  first and third job both having a deadline 2 give the highest profit. 
Profit = 100 + 27 = 127
*/


#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int data;
    int profit;
};

class Solution{
 public:
 bool static comp(Job a, Job b){
    return (a.profit>b.profit);
 }

 pair<int, int> jobScheduling(Job arr[], int n){
    sort(arr,arr+n, comp);
    int maxi = arr[0].dead;

    for(int i=0;i<n;i++){
        maxi = max(maxi, arr[i].dead);
    }

    int slot [maxi + i];
    for(int i =0;i<maxi;i++){
        slot[i] = -1;
    }

    int countJobs = 0, jobProfit = 0;
    for(int i =0; i<n;i++){
        for(int j = arr[i].dead;j>0;j--){
            if(slot[j] == -1){
                slot[j] = i;
                countJobs++;
                jobProfit +=arr[i].profit;
                break;
            }
        }
    }
    return makePair(countJobs, jobProfit);
 }
};