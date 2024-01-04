#include <bits/stdc++.h>
using namespace std;
#define ll long long int


/*

Author : Atishay Gupta
Date : 04/01/2024
Problem : Minimum Number of Operations to make Array Empty
Difficulty : Medium
Problem Link :https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/?envType=daily-question&envId=2024-01-04

*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums) mp[it]++;
        int ans = 0;
        for(auto it: mp){
            int n = it.second;
            if(n==1) return -1;
            int div = n/3;
            int r  = n%3;
            if(r==0) ans+=div;
            else if(r==1) ans = ans + div-1 + 2;
            else ans+=div + 1; 
        }

        return ans;
    }
};