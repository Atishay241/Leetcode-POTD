/*

Author : Atishay Gupta
Date : 18/01/2024
Problem : Climbing Stairs
Difficulty : Medium
Problem Link : https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[50];
    int rec(int i,int n){
        if(i==n){
            return 1;
        }
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = rec(i+1,n) + rec(i+2,n);

        return dp[i] = ans;
    }
    int climbStairs(int n) {
        memset(dp , -1,sizeof(dp));
        return rec(0,n);
    }
};