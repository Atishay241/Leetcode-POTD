#include <bits/stdc++.h>
using namespace std;
#define ll long long int


/*

Author : Atishay Gupta
Date : 04/01/2024
Problem : Longest Increasing Subsequence
Difficulty : Medium
Problem Link :https://leetcode.com/problems/longest-increasing-subsequence/submissions/1137777382/?envType=daily-question&envId=2024-01-05

*/

class Solution {
public:
    int ans(int idx,int prev,vector<int>&arr,vector<vector<int>> &dp){
        if(idx<0) return 0;
       if(dp[idx][prev+1]!=0) return dp[idx][prev+1];
        int notpick = ans(idx-1,prev,arr,dp);
        int pick=0;
        if(prev==-1 || arr[idx]<arr[prev]) pick= 1 + ans(idx-1,idx,arr,dp);

        return dp[idx][prev+1] = max(pick,notpick);
    }
    
    
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // ans(n-1,-1,arr,dp);



        for(int idx=1;idx<=n;idx++){
                int a = dp[idx-1][0];
                int b = 1 + dp[idx-1][idx];
                dp[idx][0] = max(a,b);
            for(int prev = idx;prev<n;prev++){
              
                int notpick = dp[idx-1][prev+1];
                int pick=0;
                if(prev==-1 || arr[idx-1]<arr[prev]){
                     pick= 1 + dp[idx-1][idx];
                }

                dp[idx][prev+1] = max(pick,notpick);
            }
        }

        // for(auto it: dp){
        //     for(auto i: it) cout<<i<<" ";
        //     cout<<endl;
        // }

        return dp[n][0];
        

        
    }
};