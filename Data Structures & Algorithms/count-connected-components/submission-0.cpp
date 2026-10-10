class Solution {
public:
    void dfs(int i,vector<vector<int>>& G,vector<bool>& vis){
        if(vis[i])return;
        vis[i] = true;
        for(int nei : G[i]){
            dfs(nei,G,vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> AdjList(n);
        for(auto& edge : edges){
            AdjList[edge[0]].push_back(edge[1]);
            AdjList[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,AdjList,vis);
            }
        }
        return ans;
    }
};
