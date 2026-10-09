class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> vis;

    bool dfs(int i,vector<vector<int>>& AdjList,vector<int>& visited){
        if(visited[i] == 2)return false;
        if(visited[i] == 1)return true;
        visited[i] = 1;
        for(int req : AdjList[i]){
            if(dfs(req,AdjList,visited))return true;
        }
        visited[i] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        if(pre.size() == 0)return true;

        vector<vector<int>> AdjList(numCourses);

        for(int i=0;i<pre.size();i++){
            AdjList[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0 && dfs(i,AdjList,visited)){
                return false;
            }
        }
        return true;
    }
};
