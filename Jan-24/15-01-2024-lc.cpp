/*

Author : Atishay Gupta
Date : 15/01/2024
Problem : Find Players With Zero or One Losses
Difficulty : Medium
Problem Link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15

*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> mp;
        for(auto it: matches){
            if(mp.find(it[0])==mp.end()) mp[it[0]] = 0;
            mp[it[1]]++;
        }
        for(auto it: mp){
            if(it.second==0) ans[0].push_back(it.first);
            else if(it.second==1) ans[1].push_back(it.first);
        }

        return ans;
    }
};
