class Solution {
public:
    int dp[2001];
    string glob;
    bool p(int i,int j){
    
        while(i<j){
            if(glob[i]!=glob[j]) return false;
            i++,j--;
        }
      
        return true;
    }
   int k;
    int func(int i){
        if(i>=glob.size()) return 0;
        if(dp[i]!=-1) return dp[i];
       int maxi=0;
        for(int j=i;j<glob.size();j++){
           
            if(p(i,j)){
                
                 if(j-i+1>=k)   maxi=max(maxi,1+func(j+1));
                else maxi=max(maxi,func(j+1));
            }
        }
       
        
        return dp[i]=maxi;
    }
    int maxPalindromes(string s, int a) {
        if(a==1) return s.size();
        memset(dp,-1,sizeof(dp));
        k=a;
       glob=s;
        return func(0);
    }
};