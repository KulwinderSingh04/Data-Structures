class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
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
        return ans.size() == n;
    }
};