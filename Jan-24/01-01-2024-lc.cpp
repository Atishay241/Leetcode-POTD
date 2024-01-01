#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*

Author : Atishay Gupta
Date : 01/01/2024
Problem : Assign Cookies
Difficulty : Easy
Problem Link : https://leetcode.com/problems/assign-cookies/submissions/1133633826/?envType=daily-question&envId=2024-01-01

*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int i = 0 , j=0 ,ans=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                i++;
                j++;
                ans++;
            }
            else{
                j++;
            }
        }

        return ans;
    }
};