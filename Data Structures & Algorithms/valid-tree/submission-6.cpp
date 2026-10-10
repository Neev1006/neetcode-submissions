class Solution {
public:
    void dfsC(int i,vector<vector<int>>& AdjList,vector<int>& vis){
        if(vis[i] == 1)return;
        vis[i] = 1;
        for(int nei : AdjList[i]){
            dfsC(nei,AdjList,vis);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.empty())return true;
        if(edges.size() != n-1)return false;

        vector<int> vis(n,0);
        vector<vector<int>> AdjList(n);
        for(auto& edge : edges){
            AdjList[edge[0]].push_back(edge[1]);
            AdjList[edge[1]].push_back(edge[0]);
        }

        dfsC(AdjList[0][0],AdjList,vis);

        for(int i=0;i<n;i++){
            if(vis[i] == 0)return false;
        }
        return true;
    }
};
