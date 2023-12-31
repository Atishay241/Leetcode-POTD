#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*

Author : Atishay Gupta
Date : 30/12/2023
Problem : Largest Substring Between Two Equal Character
Difficulty : Easy
Problem Link : https://leetcode.com/problems/largest-substring-between-two-equal-characters/?envType=daily-question&envId=2023-12-31

*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> adj[26];
        int i = 0;
        int ans = -1;
        for(auto it: s){
            int sz = adj[it-'a'].size();
            if(sz<2){
                adj[it-'a'].push_back(i);
                sz++;
                if(sz==2) ans = max(ans , adj[it-'a'][1] - adj[it-'a'][0] - 1);
            } 
            else{
                adj[it-'a'][1] = i;
                ans = max(ans , adj[it-'a'][1] - adj[it-'a'][0] - 1);
            }

            i++;
        }

        return ans;

    }
};

