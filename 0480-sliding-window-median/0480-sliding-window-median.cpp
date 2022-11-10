class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>ans;
        multiset<int>s(begin(nums),begin(nums)+k);
        
        auto mid=next(s.begin(),k/2);
        for(int i=k;;i++){
            ans.push_back((double(*mid)+*prev(mid,1-k%2))/2.0);
            if(i==nums.size()) return ans;
            s.insert(nums[i]);
            if(nums[i]<*mid){
                mid--;
            }
           
            if(nums[i-k]<=*mid) mid++;
          
            s.erase(s.lower_bound(nums[i-k]));
        }
        return ans;
    }
};