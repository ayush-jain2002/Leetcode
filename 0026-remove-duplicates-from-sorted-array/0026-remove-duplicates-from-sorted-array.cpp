class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
       
        for(;j<n;j++){
           while(j<n-1 && nums[j]==nums[j+1]) j++;
            swap(nums[i++],nums[j]);
        }
       
        i=1;
        while(i<n && nums[i]>nums[i-1]) i++;
        return i;
        
    }
};