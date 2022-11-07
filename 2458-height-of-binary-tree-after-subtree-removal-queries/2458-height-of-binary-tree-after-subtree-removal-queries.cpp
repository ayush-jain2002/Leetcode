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
    //Euler Tour Method
    vector<int>mhl,mhr,tour;
    unordered_map<int,int>h,first,last;
    void dfs(TreeNode* root,int d){
        if(!root) return;
        h[root->val]=d;
        first[root->val]=tour.size();
        tour.push_back(root->val);
        dfs(root->left,d+1);
        dfs(root->right,d+1);
        last[root->val]=tour.size();
        tour.push_back(root->val);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        dfs(root,0);
        int n=tour.size();
        mhl.resize(n,0);
        mhr.resize(n,0);
        mhl[0]=mhr[n-1]=h[root->val];
        for(int i=1;i<n;i++) mhl[i]=max(mhl[i-1],h[tour[i]]);
          for(int i=tour.size()-2;i>=0;i--)mhr[i]=max(mhr[i+1],h[tour[i]]);
        vector<int>res;
        for(auto i:q){
            res.push_back(max(mhl[first[i]-1],mhr[last[i]+1]));
        }
        return res;
    }
};