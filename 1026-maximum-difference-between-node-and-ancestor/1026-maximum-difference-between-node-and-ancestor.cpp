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
    int maxi=INT_MIN;
    void dfs(TreeNode* root,map<int,int>&s){
        if(!root) return;
        if(s.size())maxi=max(maxi,max(abs(s.begin()->first-root->val),abs(s.rbegin()->first-root->val)));
        s[root->val]++;
        dfs(root->left,s);
        
        dfs(root->right,s);
        s[root->val]--;
        if(s[root->val]==0) s.erase(root->val);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        map<int,int> s;
        dfs(root,s);
        return maxi;
    }
};