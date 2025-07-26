// problem: https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
// approach : recursion using take not take approach 

void subsetSumHelper(int ind, vector<int>&ans, vector<int>arr, int n, int sum){
    if(ind == arr.size()){
        ans.push_back(sum);
    }

    subsetSumHelper(ind, ans, arr, n, sum+arr[i]);
    subsetSumHemper(ind, ans, arr, n, sum);
}

vector<int> subsetSum(vector<int>arr, int n){
    vector<int>ans;
    subsetSumHelper(0, ans, arr, n, 0);
    sort(arr.begin(), arr.end());
    return ans;
}