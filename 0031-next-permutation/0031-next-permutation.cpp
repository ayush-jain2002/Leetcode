class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        int i=n-1;
        while(i>0 && nums[i-1]>=nums[i]) i--;
        i--;
        if(i<0){
            reverse(begin(nums),end(nums));
            return;
        }
        int j=n-1;
        while(j>i){
            if(nums[j]>nums[i]) {swap(nums[j],nums[i]);break;}
            j--;
        }
        reverse(nums.begin()+i+1,nums.end());
        return;
        
    }
};