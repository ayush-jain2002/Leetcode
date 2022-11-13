class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string t="";
        for(int i=0;i<s.size();i++){
        if(s[i]!=' ') t+=s[i];
            else if(i<s.size()-1 && s[i]==' ' && s[i+1]!=' '){
                if(t.size()) st.push(t),t="";
               
            }
           
          
        }
        st.push(t);
        string ans="";
        while(!st.empty()){
           
            ans+=st.top();
            st.pop();
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};