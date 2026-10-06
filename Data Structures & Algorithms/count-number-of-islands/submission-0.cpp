class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x , int y , vector<vector<char>>& grid , vector<vector<bool>> &vis , int m , int n){
        if(x<0 || x >= m || y<0 || y>=n || vis[x][y] || grid[x][y] == '0')return;
        vis[x][y] = true;
        for(int i=0;i<4;i++){
            int r = x + dx[i];
            int c = y + dy[i];
            dfs(r,c,grid,vis,m,n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,grid,vis,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
};
