class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indegree(n);
        for(int i = 1; i < n; i++) {
            for(auto x : adj[i]) {
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i = 1; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto x : adj[t]) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> mat(k, vector<int> (k));
        vector<vector<int>> adj1(k + 1), adj2(k + 1);
        for(auto x : rowConditions) {
            adj1[x[0]].push_back(x[1]);
        }
        for(auto x : colConditions) {
            adj2[x[0]].push_back(x[1]);
        }
        vector<int> rowSort = topoSort(adj1);
        vector<int> colSort = topoSort(adj2);
        if(rowSort.size() != k || colSort.size() != k) return {};
        unordered_map<int, int> mp1;
        for(int i = 0; i < k; i++) {
            mp1[colSort[i]] = i;
        }
        for(int row = 0; row < k; row++) {
            mat[row][mp1[rowSort[row]]] = rowSort[row];
        }
        return mat;
    }
};