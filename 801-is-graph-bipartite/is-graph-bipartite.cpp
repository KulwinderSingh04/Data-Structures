class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, int color , vector<int>& colArr) {
        colArr[i] = color;
        for(auto t : graph[i]) {
            if(colArr[t] == -1) {
                colArr[t] = !color;
                bool a = dfs(graph, t, !color, colArr);
                if(a == false) return a;
            }
            else {
                if(colArr[t] == color) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colArr(n, -1);
        for(int i = 0; i < n; i++) {
            if(colArr[i] == -1) {
                bool a = dfs(graph, i, 0, colArr);
                if(a == false) return a;
            }
        }
        return true;
    }
};