/*

Author : Atishay Gupta
Date : 11/01/2024
Problem : Maximum Difference Between Node and Ancestor
Difficulty : Medium
Problem Link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/?envType=daily-question&envId=2024-01-11

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rec(TreeNode * root , int mini , int maxi , int &ans){
        if(root==NULL){
            ans = max(ans , maxi - mini);
            return;
        }
        maxi = max(root->val , maxi);
        mini = min(root->val ,mini);

        rec(root->left , mini , maxi , ans);
        rec(root->right , mini , maxi , ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        rec(root , root->val , root->val , ans);
        return ans;
    }
};

