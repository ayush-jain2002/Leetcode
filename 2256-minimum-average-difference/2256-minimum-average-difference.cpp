class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long >prefix(n,0);
           int ind=-1;
        for(int i=0;i<n;i++){
            prefix[i]=nums[i];
            if(i>0)prefix[i]+=prefix[i-1];
        }
        int mini=INT_MAX;
        long long sum=prefix[n-1];
        for(int i=0;i<n;i++){
            int avg1=((prefix[i]+0.0)/(i+1));
            int  avg2=(i<n-1)?((sum-prefix[i]+0.0)/(n-i-1)):0;
           int avg=abs(avg1-avg2);
            if(mini>avg){
            mini=min(mini,abs(avg1-avg2));
                ind=i;
            }
        }
        return ind;
    }
};