class Solution {
public:
    #define ll long long
    vector<int>r;
   vector<int>f;
    ll dp[101][10001];
   
    ll func(int i,int j){
        if(i==r.size()) return 0;
        if(j==f.size()) return 1e13;
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans=1e13;
        ans=min(ans,func(i+1,j+1)+abs(r[i]-f[j]));
        ans=min(ans,func(i,j+1));
        return dp[i][j]=ans;
    }
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factory) {
        r=robots;
        sort(begin(r),end(r));
        memset(dp,-1,sizeof(dp));
        for(auto i:factory){
            for(int j=0;j<i[1];j++)f.push_back(i[0]);
        }
        sort(begin(f),end(f));
        return func(0,0);
       
    }
};