class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int m = grid.size(),n = grid[0].size();
        bool foundFresh = false;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    grid[i][j] = 0;
                    rotten.push({i,j});
                }
                else if(grid[i][j] == 1){
                    foundFresh = true;
                    grid[i][j] = INT_MAX;
                }
                else{
                    grid[i][j] = -1;
                }
            }
        }

        if(rotten.empty()){
            if(foundFresh)return -1;
            else{
                return 0;
            }
        };

        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};

        while(!rotten.empty()){
            auto[x,y] = rotten.front();
            rotten.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny] != INT_MAX)continue;
                grid[nx][ny] = grid[x][y] + 1;
                rotten.push({nx,ny});
            }
        }
        int mini = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == INT_MAX)return -1;
                else if(grid[i][j] != -1){
                    mini = max(mini,grid[i][j]);
                }
            }
        }
        return mini;
    }
};
