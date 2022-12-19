class Solution {
public:
    vector<int>uf;
    int find(int x){
        if(uf[x]==x) return x;
        return uf[x]=find(uf[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        uf.resize(26,0);
        iota(begin(uf),end(uf),0);
        for(auto &it:equations){
            if(it[1]=='=') uf[find(it[0]-'a')]=find(it[3]-'a');
        }
        for(auto &it:equations){
            if(it[1]=='!' && find(it[0]-'a')==find(it[3]-'a')) return false;
        }
        return true;
    }
};