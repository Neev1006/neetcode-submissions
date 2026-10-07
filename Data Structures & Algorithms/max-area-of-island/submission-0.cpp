class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int i , int j , vector<vector<int>>& grid,int &ans , int m , int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0)return;
        ans += 1;
        grid[i][j] = 0;
        for(int a=0;a<4;a++){
            int x = i + dx[a];
            int y = j + dy[a];
            dfs(x,y,grid,ans,m,n);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i,j,grid,area,m,n);
                    maxi = max(maxi,area);
                }
            }
        }
        return maxi;
    }
};
