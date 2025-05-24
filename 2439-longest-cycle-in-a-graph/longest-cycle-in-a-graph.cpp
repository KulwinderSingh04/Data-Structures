class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int>& arr, vector<int>& count, int& ans, int timer) {
        if(node == -1) return;
        vis[node] = 1;
        pathVis[node] = 1;
        count[node] = timer;
        if(arr[node] != -1 && vis[arr[node]] == 1 && pathVis[arr[node]] == 1) {
            ans = max(ans, count[node] - count[arr[node]] + 1);
        } else if(arr[node] != -1 && vis[arr[node]] == 0) {
            dfs(arr[node], vis, pathVis, arr, count, ans, timer + 1);
        }
        pathVis[node] = 0;
    }
    int longestCycle(vector<int>& arr) {
        int n = arr.size();
        vector<int> pathVis(n);
        vector<int> vis(n), count(n, 1);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i, vis, pathVis, arr, count, ans, 1);
            }
        }
        return ans;
    }
};