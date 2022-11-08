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
    TreeNode* r;
   bool f(TreeNode* r1,TreeNode* r2){
      if(!r1 || !r2) return r1==r2;
       return r1->val==r2->val && f(r1->left,r2->left) && f(r1->right,r2->right);
   }
    bool ans=false;
    void dfs(TreeNode* root){
        if(!root) return;
        if(root->val==r->val) ans|=f(root,r);
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
        
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        r=subRoot;
        dfs(root);
        return ans;
    }
};