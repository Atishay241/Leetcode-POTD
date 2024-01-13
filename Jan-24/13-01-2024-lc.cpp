/*

Author : Atishay Gupta
Date : 12/01/2024
Problem : Minimum Number of Steps to Make Two Strings Anagram
Difficulty : Medium
Problem Link : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/?envType=daily-question&envId=2024-01-13

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> arr(26,0);
        int ans = s.size();
        for(auto it: s){
            arr[it - 'a']++;
        }
        for(auto it: t){
            if(arr[it-'a']>0){
                ans--;
                arr[it-'a']--;
            }
        }

        return ans;
    }
};
