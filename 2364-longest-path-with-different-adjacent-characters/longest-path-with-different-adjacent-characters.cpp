class Solution {
public:
    typedef pair<int, int> pp;
    pp fun(int node, int par, int& ans, vector<vector<int>>& adj, string& s) {
        vector<pp> v;
        for(auto x : adj[node]) {
            if(x != par) {
                pp a = fun(x, node, ans, adj, s);
                // cout << a.first << " " << a.second << endl;
                v.push_back(a);
            }
        }
        sort(v.begin(), v.end(), greater<pp>());
        int a = -1, b = -1;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].second != s[node]) {
                if(a == -1) a = i;
                else b = i;
            }
            if(b != -1) break;
        }
        if(a == -1) {
            return {1, s[node]};
        }
        if(b == -1) {
            ans = max(ans, v[a].first + 1);
            return {v[a].first + 1, s[node]};
        }
        ans = max(ans, v[a].first + v[b].first + 1);
        return {max(v[b].first, v[a].first) + 1, s[node]};
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int ans = 1;
        fun(0, -1, ans, adj, s);
        return ans;
    }
};