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
                if(b[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(b,c,i,j)){
                            b[i][j]=c;
                            if(func(b)==true){
                                return true;
                            }
                            else{
                                b[i][j]='.';
                            }
                        }
                        
                    }
                          return false;
                    
                }
          
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
};