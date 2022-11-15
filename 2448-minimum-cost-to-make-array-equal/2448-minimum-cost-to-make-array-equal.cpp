class Solution {
public:
    #define ll long long
    ll minCost(vector<int>& nums, vector<int>& cost) {
       
        ll ans=LLONG_MAX;
        int n=nums.size();
         vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={nums[i],cost[i]};
        }
        sort(begin(v),end(v));
        vector<ll>prefix(n,0),suffix(n,0);
       ll cost_sum=0,sigma=0;
        
        for(int i=0;i<n;i++){
          prefix[i]=v[i].first*cost_sum-sigma;
            cost_sum+=v[i].second;
            sigma+=(v[i].first*1LL*v[i].second);
        }
        cost_sum=0,sigma=0;
        for(int i=n-1;i>=0;i--){
                    suffix[i]=v[i].first*cost_sum-sigma;
            cost_sum+=v[i].second;
            sigma+=(v[i].first*1LL*v[i].second);
            
        }
        for(int i=0;i<n;i++){
            ans=min(ans,prefix[i]-suffix[i]);
        }
        
        return ans;
    }
};