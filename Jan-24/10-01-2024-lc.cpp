/*

Author : Atishay Gupta
Date : 10/01/2024
Problem : Amount of Time for Binary Tree to be Effected
Difficulty : Medium
Problem Link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10

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
    TreeNode * node;

    void rec(TreeNode* root, int start,map<TreeNode * , TreeNode *> &mp){
        if(root==NULL){
            return ;
        }
        if(root->val==start){
            node = root;
        }
        if(root->left){
            rec(root->left , start,mp);
            mp[root->left] = root;
        }
        
         if(root->right){
            rec(root->right , start,mp);
            mp[root->right] = root;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;

        node = NULL;

        map<TreeNode * , TreeNode *> mp;

        mp[root] = NULL;

        rec(root,start,mp);

        // cout<<"jk\n";


        unordered_map<int,int> mp1;

        queue<pair<TreeNode* , int> > q;

        q.push({node , 0});

        while(!q.empty()){
            auto n = q.front();
            q.pop();
            // cout<<n.first->val<<" "<<n.second<<"\n";
            ans = max(ans , n.second);

            mp1[n.first->val] = 1;

            if(n.first->left!=NULL && (mp1.find(n.first->left->val)==mp1.end())){
                q.push({n.first->left , n.second + 1});
            }

            if(n.first->right!=NULL && (mp1.find(n.first->right->val)==mp1.end())){
                q.push({n.first->right , n.second + 1});
            }

            TreeNode * up = mp[n.first];

            if(up!=NULL && (mp1.find(up->val)==mp1.end())){
                q.push({up , n.second + 1});
            }

        }

        return ans;
    }
};