class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, vector<int>& vis, vector<int>& pathVis) {
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto x : graph[i]) {
            if(vis[x] == 0) {
                bool a = dfs(graph, x, vis, pathVis);
                if(a) return a;
            }
            else if(pathVis[x] == 1) return true;
        }
        pathVis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> vis(n), pathVis(n);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(graph, i, vis, pathVis);
            }
        }
        for(int i = 0; i < n; i++) {
            if(pathVis[i] == 0) ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};