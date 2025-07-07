#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution{
 public:
    bool static comp(Item a, Item b){
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return r1>r2;
    }

    double fractionalKnapsack(int w, Item arr[], int n ){
        sort(arr,arr+n,comp);
        int currWt = 0;
        double finalValue = 0.0;

        for(int i =0;i<n;i++){
            if(currWt + arr[i].weight<=W){
                currWt +=arr[i].weight;
                finalValue+=arr[i].value;
            }
            else{
                int remain = w - currWt;
                finalValue +=((double) arr[i].value/(double)arr[i].weight) * (double) remain;
                break;
            }
        }
        return finalValue;
    }



};