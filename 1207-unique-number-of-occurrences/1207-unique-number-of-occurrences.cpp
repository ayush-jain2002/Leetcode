class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp,mp1;
        
        for(auto it:arr) mp[it]++;
        for(auto i:mp) mp1[i.second]++;
       for(auto i:mp1) if(i.second>1) return false;
        return true;
    }
};