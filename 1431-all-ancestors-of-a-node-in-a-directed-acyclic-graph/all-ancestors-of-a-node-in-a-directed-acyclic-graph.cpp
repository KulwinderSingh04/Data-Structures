class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for(auto& x : adj[node]) {
            if(vis[x] == 0) dfs(x, adj, vis, st);
        }
        st.push(node);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // cout << edges.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        vector<int> vis(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i, adj, vis, st);
            }
        }
        vector<int> topoSort;
        while(st.size()) {
            topoSort.push_back(st.top());
            st.pop();
        }
        vector<set<int>> ancestor(n);
        for(int i = 0; i < n; i++) {
            for(auto x : adj[topoSort[i]]) {
                ancestor[x].insert(topoSort[i]);
                for(auto t : ancestor[topoSort[i]]) {
                    ancestor[x].insert(t);
                }
            }
        }
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            for(auto x : ancestor[i]) {
                ans[i].push_back(x);
            }
        }
        return ans;
    }
};