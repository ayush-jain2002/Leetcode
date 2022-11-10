class Solution {
public:
    string removeDuplicates(string s, int k) {
          vector<pair<char,int>>st;
        for(char &ch:s){
            if(!st.empty() && st.back().first==ch){
                st.back().second+=1;
            }
            else st.push_back({ch,1});
            if(st.back().second==k){
               st.pop_back();
            }
        }
        string ans="";
        while(!st.empty()){
           ans.append(st.back().second,st.back().first);
            st.pop_back();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};