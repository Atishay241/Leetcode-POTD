/*

Author : Atishay Gupta
Date : 12/01/2024
Problem : Determine If String Halves are Alike
Difficulty : Easy
Problem Link : https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=Invalid%20Date

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
         c=='A' || c=='E' || c=='I' || c=='O' || c=='U' ) return true;

        return false;

    }
    bool halvesAreAlike(string s) {
        int a = 0 , b = 0 , n = s.size();

        for(int i=0;i<n;i++){
            if(i<n/2){
                if(check(s[i])) a++;
            }
            else{
                if(check(s[i])) b++;
            }
        }

        return a==b;
    }
};