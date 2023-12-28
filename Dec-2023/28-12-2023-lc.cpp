#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*

Author : Atishay Gupta
Date : 27/12/2023
Problem : String Compression 2
Difficulty : Hard
Problem Link : https://leetcode.com/problems/string-compression-ii/description/?envType=daily-question&envId=2023-12-28

*/

int dp[101][27][101][101];

class Solution {
public:
    unordered_set<int> c{1,9,99};

    int rec(int i,int n,string &s , int last , int cnt,int k){

        if(k<0) return 1e7;
        if(i==n) return 0;

        if(dp[i][last][cnt][k]!=-1) return dp[i][last][cnt][k];
        
        int ans1 = rec(i+1 , n , s , last , cnt , k - 1);
        int ans2;
        if(s[i] - 'a' ==last){
            ans2 = rec(i+1 , n ,s , last , cnt + 1 , k) + (c.count(cnt) ? 1 : 0);
        }
        if(s[i] - 'a' !=last){
            ans2 = 1 + rec(i+1 , n , s , s[i] - 'a' , 1 , k);
        }

        return dp[i][last][cnt][k] = min(ans1 , ans2);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();

        memset(dp,-1,sizeof(dp));

        return rec(0,n,s,26, 0 , k);
    }
};