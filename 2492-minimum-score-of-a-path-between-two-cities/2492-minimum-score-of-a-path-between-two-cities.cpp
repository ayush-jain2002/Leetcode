class Solution {
public:
    int mini;
    int n;
    bool check=false;
    void dfs(vector<pair<int,int>>adj[],int node,vector<int>&vis){
        vis[node]=1;
       
        
        for(auto child:adj[node]){
             mini=min(mini,child.second);
           if(!vis[child.first])
             dfs(adj,child.first,vis);
        }
    }
    int minScore(int ni, vector<vector<int>>& roads) {
        n=ni;
        vector<pair<int,int>>adj[n+1];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
       mini=roads[0][2];
        vector<int>vis(n+1,0);
        dfs(adj,1,vis);
        return mini;
    }
};