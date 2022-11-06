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
 #define tn TreeNode*
map<pair<tn,pair<bool,bool>>,int>dp;
class Solution {
public:
    int solve(tn root,bool cam,bool parcam){
        if(!root){
            if(cam) return 1e9;
            else return 0;
        }
        if(!root->left && !root->right){
            if(cam) return 1;
            else{
                if(parcam) return 0;
                else return 1e9;
            }
        }
        if(dp.find({root,{cam,parcam}})!=dp.end()) return dp[{root,{cam,parcam}}];
        if(cam){
            dp[{root,{cam,parcam}}]=1+min(solve(root->left,0,1),solve(root->left,1,1))+min(solve(root->right,0,1),solve(root->right,1,1));
        }
        else{
            if(parcam){
                 dp[{root,{cam,parcam}}]=min(solve(root->left,0,0),solve(root->left,1,0))+min(solve(root->right,0,0),solve(root->right,1,0));
            }
            else{
                int op1=solve(root->left,1,0)+min(solve(root->right,1,0),solve(root->right,0,0));
                 int op2=solve(root->right,1,0)+min(solve(root->left,1,0),solve(root->left,0,0));
                dp[{root,{cam,parcam}}]=min(op1,op2);
            }
        }
        return dp[{root,{cam,parcam}}];
        
    }
   
    int minCameraCover(TreeNode* root) {
        dp.clear();
        return min(solve(root,1,0),solve(root,0,0));
    }
};