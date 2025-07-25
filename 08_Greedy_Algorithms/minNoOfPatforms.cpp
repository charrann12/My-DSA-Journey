/*
Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

Examples 1:

Input: N=6, 
arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00} 
dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}

Output:3

*/

int countPlatforms(int arr[], int dep[], int n){
    sort(arr, arr+n);
    sort(dep,dep+n);

    int ans =1,count=1,i=1,j=0;

    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }

        ans = max(ans, count);


    }
    return ans;
}