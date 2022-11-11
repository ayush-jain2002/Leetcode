class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=1,j=1,c=1;
        for(;j<n;j++){
            if(nums[j]!=nums[j-1]){
                nums[i++]=nums[j];
                c=1;
            }
            else if(c==1){
                nums[i++]=nums[j];
                c=2;
            }
        }
        return i;
        
    }
};