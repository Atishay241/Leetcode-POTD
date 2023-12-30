#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*

Author : Atishay Gupta
Date : 30/12/2023
Problem : Redistribute Characters to make all String Equal
Difficulty : Easy
Problem Link : https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/?envType=daily-question&envId=2023-12-30

*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> arr(26,0);
        for(auto it: words){
            for(auto i : it){
                arr[i - 'a']++;
            }
        }
        int n = words.size();
        for(int i=0;i<26;i++){
            if(arr[i]%n!=0) return 0;
        }
        return 1;
    }
};