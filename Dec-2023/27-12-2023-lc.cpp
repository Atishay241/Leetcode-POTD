#include <bits/stdc++.h>
using namespace std;
#define ll long long int


/*

Author : Atishay Gupta
Date : 27/12/2023
Problem : Minimum Time to make rope colorful
Difficulty : Medium
Problem Link : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2023-12-27

*/

class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int ans = 0;
        int mini = arr[0];
        int i = 1 , cnt = 1;
        char c = colors[0];
        int n = arr.size();
        int sum = accumulate(arr.begin() , arr.end(),0);
        cout<<sum<<"\n";
        while(i<n){
            if(colors[i]==c){
                cnt++;
                mini = max(mini , arr[i]);
            }
            else{
                ans+=mini;
                cnt = 1;
                mini = arr[i];
                c = colors[i];
            }
            i++;
        }
        ans+= mini;

        return sum - ans;

    }
};