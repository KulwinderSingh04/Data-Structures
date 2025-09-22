class Solution {
public:
    vector<int> topoSort(vector<int>& indegree, vector<vector<int>>& adj) {
        queue<int> q;
        int n = indegree.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);
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
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> indegree(n);
        queue<int> q;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            indegree[i] = beforeItems[i].size();
            for(int j = 0; j < beforeItems[i].size(); j++) {
                adj[beforeItems[i][j]].push_back(i);
            }
        }
        vector<int> v1 = topoSort(indegree, adj);
        if(v1.size() != n) return {};
        unordered_map<int, int> mp;
        int t = m;
        for(int i = 0; i < n; i++) {
            if(group[i] == -1) {
                mp[i] = t++;
            } else mp[i] = group[i];
        }
        vector<int> indegree2(t);
        vector<vector<int>> adj2(t);
        set<vector<int>> st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < beforeItems[i].size(); j++) {
                int g1 = mp[beforeItems[i][j]];
                int g2 = mp[i];
                if(st.find({g1, g2}) != st.end()) continue;
                if(g1 == g2) continue;
                indegree2[g2]++;
                adj2[g1].push_back(g2);
                st.insert({g1, g2});
            }
        }
        vector<int> v2 = topoSort(indegree2, adj2);
        if(v2.size() != t) return {};
        unordered_map<int, vector<int>> grpMap;
        for(int i = 0; i < n; i++) {
            int g = mp[v1[i]];
            grpMap[g].push_back(v1[i]);
        }
        vector<int> ans;
        for(int i = 0; i < v2.size(); i++) {
            ans.insert(ans.end(), grpMap[v2[i]].begin(), grpMap[v2[i]].end());
        }
        return ans;
        
    }
};