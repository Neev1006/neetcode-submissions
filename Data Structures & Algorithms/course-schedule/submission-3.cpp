class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> vis;

    bool dfs(int c){
        if(vis.count(c)){
            cout<<c;
            return false;
        };
        if(mp.find(c) == mp.end())return true;

        vis.insert(c);
        for(int pr : mp[c]){
            if(!dfs(pr))return false;
        }
        vis.erase(c);
        mp[c].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        if(pre.size() == 0)return true;

        for(int i=0;i<pre.size();i++){
            mp[pre[i][0]].push_back(pre[i][1]);
        }

        for(int c=0;c<numCourses;c++){
            if(!dfs(c)){
                cout<<c;
                return false;
            }
        }

        return true;
    }
};
