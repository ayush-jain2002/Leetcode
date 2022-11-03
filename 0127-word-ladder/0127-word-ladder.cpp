class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        unordered_set<string>s;
        for(auto it:w) s.insert(it);
        queue<pair<string,int>>q;
        q.push({b,1});
        int mini=INT_MAX;
        while(!q.empty()){
            auto [str,x]=q.front();
            q.pop();
            if(str==e) mini=min(mini,x);
            for(int j=0;j<str.size();j++){
               
                for(int i=0;i<26;i++){
                     string temp=str;
                    temp[j]=('a'+(temp[j]-'a'+i)%26);
                    if(s.find(temp)!=s.end()){
                       s.erase(temp);
                        q.push({temp,x+1});
                    }
                }
            }
        }
        return mini==INT_MAX?0:mini;
    }
};