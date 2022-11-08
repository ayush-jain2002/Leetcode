class Solution {
public:
    long long totalCost(vector<int>& nums, int c, int k) {
        long long ans=0;
        int n=nums.size();
       set<pair<int,int>>s;
       int l=0,r=n-1;
        for(int i=0;i<k;i++){
            if(l<=r) s.insert({nums[l],l}),l++;
        
        }
        for(int i=0;i<k;i++){
            if(l<=r) s.insert({nums[r],r}),r--;
          
        }
        while(c--){
            int curr=s.begin()->second;
            ans+=s.begin()->first;
            s.erase(s.begin());
            if(curr<l && l<=r){
                s.insert({nums[l],l}),l++;
            }
            else if(curr>r && l<=r){
                  s.insert({nums[r],r}),r--;
            }
        }
        return ans;
    }
};