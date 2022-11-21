class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();

        vector<pair<int,int>> pos = {{0,1},{0,-1},{1,0},{-1,0}};
        int sr = entrance[0];
        int sc = entrance[1];
        queue<pair<pair<int,int>,int>> q;
        q.push({{sr,sc},0});
        maze[sr][sc]='+';
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;

            q.pop();

            for(auto i:pos)
            {
                int newR = x+i.first;
                int newC = y+i.second;

                if(newR>=0 && newR<r && newC>=0 && newC<c && maze[newR][newC]=='.')
                {
                    if(newR==0 || newR==r-1 || newC == 0 || newC==c-1)
                    return d+1;

                    maze[newR][newC]='+';
                    q.push({{newR,newC},d+1});
                }
            }
        }
        return -1;
    }
};