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
    int func(TreeNode* root,int l,int r){
        if(!root) return 0;
        int ans=0;
        if(root->val>=l && root->val<=r) ans+=root->val+func(root->left,l,r)+func(root->right,l,r);
        else if(root->val<l) ans+=func(root->right,l,r);
        else ans+=func(root->left,l,r);
        return ans;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return func(root,low,high);
    }
};