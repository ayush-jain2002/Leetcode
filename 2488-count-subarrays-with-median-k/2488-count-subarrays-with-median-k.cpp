class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int cnts=0,cntg=0;
        bool found=false;
        int ans=0;
        mp[0]++;
        for(int i=0;i<n;i++){
            if(nums[i]<k) cnts++;
            else if(nums[i]>k) cntg++;
            else if(nums[i]==k) found=true;
            int diff=cntg-cnts;
            if(found){
                if(mp.find(diff)!=mp.end()) ans+=mp[diff];
                if(mp.find(diff-1)!=mp.end()) ans+=mp[diff-1];
            }
            else mp[diff]++;
        }
        return ans;
    }
};