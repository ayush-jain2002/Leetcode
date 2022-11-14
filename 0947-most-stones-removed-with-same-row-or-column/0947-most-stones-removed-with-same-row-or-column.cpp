class Solution {
public:
    void dfs(vector<int>&vis,vector<vector<int>>&stones,int node){
        vis[node]=1;
        for(int i=0;i<stones.size();i++){
            if(!vis[i] && (stones[i][0]==stones[node][0] || stones[i][1]==stones[node][1])){
                dfs(vis,stones,i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(vis,stones,i);
                
            }
            else ans++;
        }
        return ans;
    }
};