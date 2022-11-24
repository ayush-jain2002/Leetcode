class Solution {
public:
    #define mod 1000000007
   int dp[1001][1001];
    bool isvalid(char &ch){
        
        if((ch=='2' || ch=='3' || ch=='5' || ch=='7')) return true;
        return false;
    }
    int func(string &s,int i,int k,int mini){
        
        if(k==1){
            if(s.size()-i>=mini &&!isvalid(s[s.size()-1]) && isvalid(s[i])) return 1;
            return 0;
        }
        if(i>=s.size()) return 0;
        if(!isvalid(s[i])) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
       
        
        long long ways=0;
        for(int j=i+mini-1;j<s.size();j++){
            if(!isvalid(s[j]))
            ways+=func(s,j+1,k-1,mini)%mod;
        }
        return dp[i][k]=ways%mod;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        memset(dp,-1,sizeof(dp));
        return func(s,0,k,minLength);
    }
};