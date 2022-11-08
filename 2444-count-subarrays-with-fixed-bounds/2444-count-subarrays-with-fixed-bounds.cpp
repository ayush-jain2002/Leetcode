class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minI = -1 , maxI = -1;
        int start = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < minK || nums[i] > maxK){
                minI = maxI = -1;
                start = i+1;
            }
            
            if(nums[i] == minK){
                minI = i;
            }
            if(nums[i] == maxK){
                maxI = i;
            }
            
            ans += max(0,min(minI,maxI)-start+1);
        }
        return ans;
    }
};