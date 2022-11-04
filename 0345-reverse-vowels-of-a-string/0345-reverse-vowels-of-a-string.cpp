class Solution {
public:
    string reverseVowels(string st) {
        unordered_set<char>s;
        s.insert('a'),s.insert('A');
         s.insert('e'),s.insert('E');
         s.insert('i'),s.insert('I');
         s.insert('o'),s.insert('O');
         s.insert('u'),s.insert('U');
        string str="";
        vector<int>v;
        for(int i=0;i<st.size();i++){
            if(s.find(st[i])!=s.end()){
                str+=st[i];
                v.push_back(i);
            }
           
        }
        if(v.size()==0) return st;
        reverse(begin(str),end(str));
        int k=0;
        for(int i=0;i<v.size();i++){
            st[v[i]]=str[k++];
        }
        return st;
    }
};