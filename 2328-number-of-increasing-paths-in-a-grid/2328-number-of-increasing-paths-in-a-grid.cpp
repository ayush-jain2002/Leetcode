class Solution {
public:
    int n,m;
    #define mod 1000000007
    #define ll long long
    ll dp[1001][1001];
    ll f(vector<vector<int>>&grid,int i,int j,int prev){
        if(i<0 || j<0 || i==n || j==m || grid[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(grid,i-1,j,grid[i][j]);
         int down=f(grid,i+1,j,grid[i][j]);
         int left=f(grid,i,j-1,grid[i][j]);
         int right=f(grid,i,j+1,grid[i][j]);
        return dp[i][j]=(1+up+down+left+right)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=f(grid,i,j,-1);
                ans%=mod;
            }
        }
        return ans;
    }
};