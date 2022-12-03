class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i:s) mp[i]++;
        map<int,set<int>>mp1;
        for(auto i:mp){
            mp1[i.second].insert(i.first);
        }
        string ans="";
        for(auto i:mp1){
            for(auto it:i.second){
                for(int k=0;k<i.first;k++){
                    ans+=it;
                }
            }
        }
       reverse(begin(ans),end(ans));
        return ans;
    }
};