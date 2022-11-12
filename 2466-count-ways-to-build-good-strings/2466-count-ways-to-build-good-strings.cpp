class Solution {
public:
    #define mod 1000000007
    #define ll long long
    int z,o;
    int dp[100001];
    
    ll func(int sz,int l,int h){
        if(sz>h) return 0;
       
        if(dp[sz]!=-1) return dp[sz];
        
        ll take1=func(sz+z,l,h);
        ll take2=func(sz+o,l,h);
        if(sz>=l) take1++;
        return dp[sz]=(take1+take2)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        z=zero,o=one;
        // l=low,h=high;
        return func(0,low,high)%mod;
        
    }
};