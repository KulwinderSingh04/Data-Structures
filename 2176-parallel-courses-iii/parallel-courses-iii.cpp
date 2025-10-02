class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1);
        for(auto rel : relations) {
            adj[rel[0]].push_back(rel[1]);
            indegree[rel[1]]++;
        }
        vector<int> v(n + 1);
        int ans = 0;
        queue<pair<int, int>> q;
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                q.push({i, time[i - 1]});
                v[i] = time[i - 1];
            }
        }
        while(q.size()) {
            int a = 0;
            auto t = q.front();
            q.pop();
            ans = max(ans, t.second);
            for(auto node : adj[t.first]) {
                indegree[node]--;
                v[node] = max(v[node], t.second);
                if(indegree[node] == 0) q.push({node, v[node] + time[node - 1]});
            }
        }
        return ans;
    }
};