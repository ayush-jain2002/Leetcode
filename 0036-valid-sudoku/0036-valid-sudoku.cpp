class Solution {
public:
    bool isvalid(vector<vector<char>>&b,char c,int i,int j){
        for(int k=0;k<9;k++){
            if(b[i][k]==c) return false;
            if(b[k][j]==c) return false;
            if(b[3*(i/3)+k/3][3*(j/3)+k%3]==c) return false;
        }
        return true;
    }
    bool func(vector<vector<char>>& b){
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]!='.'){
                      char c=b[i][j];
                    b[i][j]='.';
                        if(!isvalid(b,c,i,j)){
                            return false;
                        }
                    b[i][j]=c;
                        
                    
                    
                }
          
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return func(board);
    }
};