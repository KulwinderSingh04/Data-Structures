class Solution {
public:
    void dfs(int node, int start, vector<vector<int>>& adj, vector<int>& vis, map<vector<int>, vector<int>>& mp, vector<bool>& ans) {
        vis[node] = 1;
        // if(start == 3) cout << node << " ";
        if(mp.find({start, node}) != mp.end()) {
            for(auto i : mp[{start, node}]) {
                ans[i] = true;
            }
        }
        for(auto x : adj[node]) {
            if(vis[x] == 0) {
                dfs(x, start, adj, vis, mp, ans);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        map<vector<int>, vector<int>> mp;
        for(int i = 0; i < queries.size(); i++) {
            mp[queries[i]].push_back(i);
        }
        vector<vector<int>> adj(numCourses);
        for(auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        vector<bool> ans(queries.size(), false);
        for(int i = 0; i < numCourses; i++) {
            vector<int> vis(numCourses);
            
            dfs(i, i, adj, vis, mp, ans);
        }
        return ans;
    }
};