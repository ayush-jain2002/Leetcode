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
    unordered_map<TreeNode*,vector<int>>dp;
    
    int rob(TreeNode* root,bool canrob=true) {
        if(!root) return 0;
        if(dp.count(root) && dp[root][canrob]!=-1) return dp[root][canrob];
        dp[root]={-1,-1};
        int dontrob=rob(root->left,true)+rob(root->right,true);
        int rb=canrob?root->val+rob(root->left,false)+rob(root->right,false):-1;
        return dp[root][canrob]=max(dontrob,rb);
    }
};