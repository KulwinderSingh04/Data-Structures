class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& a, vector<vector<int>>& ans) {
        int n = graph.size();
        a.push_back(node);
        if(node == n - 1) {
            ans.push_back(a);
            a.pop_back();
            return;
        }
        for(auto x : graph[node]) {
            dfs(x, graph, a, ans);
        }
        a.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> a;
        dfs(0, graph, a, ans);
        return ans;
    }
};