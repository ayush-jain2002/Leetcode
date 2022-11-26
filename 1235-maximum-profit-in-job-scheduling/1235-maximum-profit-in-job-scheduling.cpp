class Solution {
public:
    vector<int>pr;
    
    int func( vector<pair<int,pair<int,int>>>&v,int i,int prev,vector<int>&dp){
        if(i==v.size()) return 0;
        if(v[prev].second.first>v[i].first) return func(v,i+1,prev,dp);
        if(dp[i]!=-1) return dp[i];
        int take=0,nottake=0;
        
       if(v[i].first>=v[prev].second.first) take=v[i].second.second+func(v,i+1,i,dp);
        nottake=func(v,i+1,prev,dp);
        return dp[i]=max(take,nottake);
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        pr=p;
       
       vector<int>dp(s.size()+1,-1);
    
        vector<pair<int,pair<int,int>>>v;
        v.push_back({0,{0,0}});
        for(int i=0;i<s.size();i++){
            v.push_back({s[i],{e[i],p[i]}});
        }
         
        sort(begin(v),end(v));
        return func(v,0,0,dp);
        
        
    }
};