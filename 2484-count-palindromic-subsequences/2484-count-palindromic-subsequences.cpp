class Solution {
public:
    string s;
    const int mod=1000000007;
    int dp[10001][11][11][6];
    int func(int i,int first,int second,int count){
       if(count==5) return 1;
        if(i==s.size()) return 0;
        if(dp[i][first][second][count]!=-1) return dp[i][first][second][count];
        long long res=func(i+1,first,second,count)%mod;
        
        if(count==0){
            res+=func(i+1,s[i]-'0',second,count+1)%mod;
        }
       else  if(count==1){
            res+=func(i+1,first,s[i]-'0',count+1)%mod;
        }
        else if(count==2){
              res+=func(i+1,first,second,count+1)%mod;
            
        }
          else if(count==3){
              if(s[i]-'0'==second){
                     res+=func(i+1,first,second,count+1)%mod;
              }
            
        }
          else if(count==4){
              if(s[i]-'0'==first){
                     res+=func(i+1,first,second,count+1)%mod;
              }
            
        }
       return dp[i][first][second][count]=res%mod;
        
    }
    int countPalindromes(string str) {
        s=str;
        memset(dp,-1,sizeof(dp));
        
        return func(0,10,10,0);
        
    }
};