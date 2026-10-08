class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int x,int y,vector<vector<char>>& board,vector<vector<int>>& vis){
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y] == 'X'|| vis[x][y] == 0)return;
        vis[x][y] = 0;
        for(int a=0;a<4;a++){
            int nx = x + dx[a];
            int ny = y + dy[a];
            dfs(nx,ny,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        //1st row
        vector<vector<int>> vis(m,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O' && vis[0][j] == -1){
                dfs(0,j,board,vis);
            }
        }
        //last row
        for(int j=0;j<n;j++){
            if(board[m-1][j] == 'O' && vis[m-1][j] == -1){
                dfs(m-1,j,board,vis);
            }
        }
        //1st column
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O' && vis[i][0] == -1){
                dfs(i,0,board,vis);
            }
        }
        //last column
        for(int i=0;i<m;i++){
            if(board[i][n-1] == 'O' && vis[i][n-1] == -1){
                dfs(i,n-1,board,vis);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && vis[i][j] == -1)board[i][j] = 'X';
            }
        }
    }
};
