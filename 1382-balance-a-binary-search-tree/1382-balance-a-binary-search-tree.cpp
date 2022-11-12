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
    
    vector<int>v;
    TreeNode* f(int l,int r){
        if(l>r) return NULL;
        TreeNode* node=new TreeNode();
        int mid=(l+r)/2;
        node->val=v[mid];
        node->left=f(l,mid-1);
        node->right=f(mid+1,r);
        return node;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        
        return f(0,v.size()-1);
    }
};