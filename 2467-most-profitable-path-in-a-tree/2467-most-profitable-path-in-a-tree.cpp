class Solution {
public:
    int maxi=INT_MIN;
    vector<int>vis;
    vector<int>val;
    int c=0;
    int x;
    vector<int>height;
    void dfs(vector<int>adj[],int node,int par,int d){
       
        height[node]=d;
        for(int child:adj[node]){
            if(child!=par)
            dfs(adj,child,node,d+1);
        }
    }
    void func(int node1,int node2,vector<int>adj[],int ans){
       
        if(!vis[node1]){
            
            ans+=(node1==node2?(val[node1]/2):val[node1]);
        }
         if(adj[node1].size()==1 && node1!=0) maxi=max(maxi,ans);
        vis[node1]=1,vis[node2]=1;
        
        for(int n1:adj[node1]){
            if(height[n1]>height[node1]){
                if(node2!=0){
                for(int n2:adj[node2]){
                    
                    if(height[n2]<height[node2]){
                        func(n1,n2,adj,ans);
                    }
                    
                }
                }
                else{
                    func(n1,0,adj,ans);
                }
               
            }
            
            
        }
         vis[node1]=0,vis[node2]=0;
       
      
  
     
       
       
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<int>adj[n];
        val=amount;
        height.resize(n,0);
       
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
         dfs(adj,0,-1,0);
       // for(auto i:height) cout<<i<<" ";
        vis.resize(n,0);
       
        func(0,bob,adj,0);
        return maxi;
    }
};