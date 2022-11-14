class Solution {
public:
 
    int dp[100001][2];
  
    int f(int i,vector<int>&n1,vector<int>&n2,int s){
        if(i==n1.size()) return 0;
        int ans=INT_MAX;
        if(dp[i][s]!=-1) return dp[i][s];
        int prev1=n1[i-1];
        int prev2=n2[i-1];
        if(s) swap(prev1,prev2);
        if(prev1<n1[i] && prev2<n2[i]){
           
            ans=min(ans,f(i+1,n1,n2,0));
        }
       if(n1[i]>prev2 && n2[i]>prev1){
           ans=min(ans,1+f(i+1,n1,n2,1));
       }
        
        return dp[i][s]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        memset(dp,-1,sizeof(dp));
     
        return f(1,nums1,nums2,0);
    }
};