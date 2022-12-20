class Solution {
public:
    //Fcking good question
   
    string longestPalindrome(string s) {
      int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int st=0,len=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dp[i][j]=1;
                if(j-i==1 && s[i]==s[j]){
                    dp[i][j]=1;
                    st=i,len=2;
                }
            }
        }
       
         for(int j=2;j<n;j++){
           
            for(int i=0;i<n;i++){
                if(j-i>=2){
                    if(s[i]==s[j] && dp[i+1][j-1]==1) dp[i][j]=1;
                }
                
                if(dp[i][j]==1 && j-i>=0 && j-i+1>len){
                    len=j-i+1;
                    st=i;
                    
                }
            }
             
        }
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //      cout<<endl;
        // }
        return s.substr(st,len);
        
        
    }
};