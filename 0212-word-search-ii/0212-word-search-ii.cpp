class Solution {
public:
    
    struct node{
        node* links[26];
        bool flag=false;
        bool containskey(char c){
            return links[c-'a']!=NULL;
        }
        void put(char c,node* n){
            links[c-'a']=n;
        }
        node* get(char c){
            return links[c-'a'];
        }
        
    };
    node* root=new node();
       vector<string>ans;
    int x,y;
    void insert(string word){
        node* n=root;
        for(int i=0;i<word.size();i++){
            if(!n->containskey(word[i])){
                n->put(word[i],new node());
            }
            n=n->get(word[i]);
        }
        n->flag=true;
        
    }
    unordered_set<string>s;
    void func(int i,int j,vector<vector<char>>&b,node* n,string &str){
        
        if(i<0 || j<0 || i==x || j==y || b[i][j]=='*' || !n->containskey(b[i][j])) return;
      
      
        str.push_back(b[i][j]);
        char c=b[i][j];
        b[i][j]='*';
          n=n->get(c);
          if(n->flag==true) s.insert(str);
        func(i+1,j,b,n,str);
        func(i,j-1,b,n,str);
        func(i,j+1,b,n,str);
        func(i-1,j,b,n,str);
        b[i][j]=c;
        str.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* n=root;
        x=board.size(),y=board[0].size();
        for(string &i:words){
            insert(i);
        }
     
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(n->containskey(board[i][j])){
                    string curr;
                   func(i,j,board,n,curr);
                }
                n=root;
            }
        }
       for(auto i:s) ans.push_back(i);
        return ans;
    }
};