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
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        vector<bool> ans;
        queue<int> q;
        vector<unordered_set<int>> parent(numCourses);
        for(int i = 0; i < numCourses; i++) if(indegree[i] == 0) q.push(i);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(auto x : adj[t]) {
                parent[x].insert(t);
                for(auto p : parent[t]) parent[x].insert(p);
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        for(auto q : queries) {
            ans.push_back(parent[q[1]].find(q[0]) != parent[q[1]].end());
        }
        return ans;
    }
};