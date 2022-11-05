class Solution {
public:
    int n,m;
    bool dfs(vector<vector<char>>& board,int i,int j,string word){
        if(!word.size()) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[0]) return false;
       
        char c=board[i][j];
        board[i][j]='*';
        string w=word.substr(1);
        bool ans= dfs(board,i,j-1,w) || dfs(board,i,j+1,w) || dfs(board,i-1,j,w) || dfs(board,i+1,j,w);
         board[i][j]=c;
        return ans;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                   
                    if(dfs(board,i,j,word)) return true;
                }
            }
        }
        return false;
    }
};