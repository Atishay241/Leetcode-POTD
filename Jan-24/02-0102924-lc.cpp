#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*

Author : Atishay Gupta
Date : 02/01/2024
Problem : Convert an Array into 2D Array with Conditions
Difficulty : Medium
Problem Link : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02

*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int maxi = -1;
        for(auto it: mp){
            int a = it.first;
            int b = it.second;
            maxi = max(maxi , b);
        }

        vector<vector<int>> ans(maxi);

        for(auto it: mp){
            int a = it.first;
            int b = it.second;
            maxi = max(maxi , b);
            for(int i=0;i<b;i++){
                ans[i].push_back(a);
            }
        }

        return ans;
    }
};