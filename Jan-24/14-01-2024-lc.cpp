/*

Author : Atishay Gupta
Date : 14/01/2024
Problem : Determine if Two Strings are Close
Difficulty : Medium
Problem Link : https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26,0) , freq2(26,0) , bool1(26,0) , bool2(26,0);
        for(auto it : word1){
            freq1[it - 'a']++;
            bool1[it-'a'] = 1;
        }

        for(auto it : word2){
            freq2[it - 'a']++;
            bool2[it - 'a'] = 1;
        }

        sort(freq1.begin() , freq1.end());
        sort(freq2.begin() , freq2.end());

        return bool1 == bool2 & freq1 == freq2;

    }
};