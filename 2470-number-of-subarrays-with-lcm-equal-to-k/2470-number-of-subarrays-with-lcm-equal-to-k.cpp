class Solution {
public:

    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;
   
        for(int i=0;i<n;i++){
           int ans=nums[i];
            for(int j=i;j<n;j++){
             ans=lcm(nums[j],ans);
              if(ans>k) break;
              if(ans==k) c++;             
              
            }
        }
        return c;
    }
};