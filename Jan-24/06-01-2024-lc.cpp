/*

Author : Atishay Gupta
Date : 06/01/2024
Problem : Maximum Profit in Job Scheduling
Difficulty : Hard
Problem Link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-01-06

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i,vector<vector<int>>& v,vector<int>& start,vector<int>& dp){
        if(i>=start.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ind=lower_bound(start.begin(),start.end(),v[i][1])-start.begin();
        int pick=v[i][2]+f(ind,v,start,dp);
        int notpick=f(i+1,v,start,dp);
        return dp[i]=max(pick,notpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        int n=profit.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
        sort(startTime.begin(),startTime.end());
        return f(0,v,startTime,dp);
    }
};