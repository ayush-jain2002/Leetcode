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
    int total=0;
    int mod=1000000007;
    map<TreeNode*,int>mp;
    int func(TreeNode* root){
        if(!root) return 0;
        int left=func(root->left);
        int right=func(root->right);
        return mp[root]=left+right+root->val;
    }
    long long ans=0;
    void dfs(TreeNode* root){
        if(!root) return;
        ans=max(ans,(total-mp[root])*1ll*(mp[root]));
        dfs(root->left);
        dfs(root->right);
    }
    int maxProduct(TreeNode* root) {
        func(root);
        total=mp[root];
        dfs(root);
        return ans%mod;
    }
};