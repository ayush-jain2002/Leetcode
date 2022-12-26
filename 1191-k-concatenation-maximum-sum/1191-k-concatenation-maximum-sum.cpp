class Solution {
public:
    const int mod=1000000007;
    int k1(vector<int>&arr){
         int n=arr.size();
         vector<long long>dp(n,0);
           dp[0]=arr[0]; 
        int maxi=max(0,(int)dp[0]);
        for(int i=1;i<n;i++){
            dp[i]=max(arr[i],(int)dp[i-1]+arr[i]);
            dp[i]%=mod;
            maxi=max(maxi,int(dp[i]));
        }
        return maxi;
    }
    int k2(vector<int>&arr){
           long sum=arr[0];
         long result=max(0,arr[0]);
        for(int i=1;i<arr.size()*2;i++){
            sum=max(sum+(arr[i%arr.size()]%mod),(long)arr[i%arr.size()]);
            result=max(result,sum);
        }
        return (int)result;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum=0;
        for(int i:arr) sum+=i,sum%=mod;
      
        if(k==1) return k1(arr);
        else if(sum<0) return k2(arr);
        else return (((k-2)*1LL*(sum))+(long)k2(arr))%mod;
    }
};