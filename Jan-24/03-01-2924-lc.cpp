#include <bits/stdc++.h>
using namespace std;
#define ll long long int


/*

Author : Atishay Gupta
Date : 03/01/2024
Problem : Number of Laser Beams in a Bank
Difficulty : Medium
Problem Link :https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03

*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int first = 0 , second = 0,ans = 0;
        for(auto it: bank){
            string s = it;
            int cnt = 0;
            for(auto i: s){
                if(i=='1') cnt++;
            }

            if(first==0) first = cnt;
            else second = cnt;

            if(first!=0 && second!=0){
                ans+=first*second;
                first = second;
                second = 0;
            }
        }

        return ans;

    }
};
