class Solution {
public:
    bool dfs(int i,vector<vector<int>>& pre,vector<int> &vis,vector<int> &ans){
        if(vis[i] == 2)return true;
        if(vis[i] == 1)return false;
        vis[i] = 1;

        for(int req : pre[i]){
            if(!dfs(req,pre,vis,ans))return false;
        }
        ans.push_back(i);
        vis[i] = 2;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int m = pre.size();
        vector<int> ans;
        vector<vector<int>> AdjList(numCourses);

        vector<int> vis(numCourses,0);

        for(int i=0;i<m;i++){
            AdjList[pre[i][0]].push_back(pre[i][1]);
        }

        for(int i=0;i<numCourses;i++){
            if(vis[i] == 0 && !dfs(i,AdjList,vis,ans)){
                return {};
            }
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i] == 0)ans.push_back(i);
        }
        return ans;
    }
};
