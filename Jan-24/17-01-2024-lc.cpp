/*

Author : Atishay Gupta
Date : 17/01/2024
Problem : Unique Number of Occurences
Difficulty : Medium
Problem Link : https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> s;
        for(auto it: arr) mp[it]++;

        for(auto it: mp){
            if(s.count(it.second)>0) return false;
            s.insert(it.second);
        }

        return true;
    }
};