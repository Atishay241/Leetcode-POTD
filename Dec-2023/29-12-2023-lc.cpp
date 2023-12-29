#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*

Author : Atishay Gupta
Date : 29/12/2023
Problem : Minimum Difficulty of a Job Schedule
Difficulty : Hard
Problem Link : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/?envType=daily-question&envId=2023-12-29

*/

class Solution {
public:
    int dp[301][11];

    int rec(int idx , int n,vector<int> &arr , int d){
        if(d<0) return 1e6;
        if(idx==n){
            if(d==0) return 0;
            return 1e6;
        }

        if(dp[idx][d]!=-1) return dp[idx][d];

        int ans = 1e7 , maxi = -1;
        for(int i = idx;i<n;i++){
            maxi = max(arr[i] ,maxi);
            int a = maxi + rec(i+1,n,arr,d-1);
            ans = min(ans,a);
        }
        return dp[idx][d] = ans;
    }

    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        if(d>n) return -1;
        memset(dp ,-1 , sizeof(dp));
        
        return rec(0,n,arr,d);
    }
};