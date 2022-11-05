class Node{
    Node* links[26];
    bool end=false;
  public:
    void insert(char ch){
        links[ch-'a'] = new Node();
    }
    
    bool isPresent(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* getNext(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        end=true;
    }
    
    bool isEnd(){
        return end;
    }
    
};

class Solution {
  
    int n,m;
    
    void solve(unordered_set<string>&res, string&curr, vector<vector<char>>&board, Node* node, int i, int j){
        
        
        if(i<0 || i==n || j<0 || j==m || board[i][j]=='*' || !node->isPresent(board[i][j])) return;
        
        char ch = board[i][j];
       
        curr+=ch;
        board[i][j]='*';
        
        node=node->getNext(ch);
        if(node->isEnd()) res.insert(curr);
        
        solve(res,curr,board,node,i+1,j);
        solve(res,curr,board,node,i-1,j);
        solve(res,curr,board,node,i,j+1);
        solve(res,curr,board,node,i,j-1);
        
        curr.pop_back();
        board[i][j]=ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        n=board.size(),m=board[0].size();
        unordered_set<string>res;
        Node* root = new Node();
        for(auto word : words){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                if(!node->isPresent(ch)) node->insert(ch);
                node=node->getNext(ch);
            }
            node->setEnd();
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch = board[i][j];
                if(!root->isPresent(ch)) continue;
                    
                string curr;
                solve(res,curr,board,root,i,j);
            }
        }
        
        vector<string>v;
        for(auto it : res) v.push_back(it);
        return v;
        
    }
};