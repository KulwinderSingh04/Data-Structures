class Solution {
public:
    bool fun1(vector<vector<int>>& adj, int bob, int time, unordered_map<int, int>& m, unordered_set<int>& s) {
        if(s.find(bob) != s.end()) return false;
        s.insert(bob);
        m[bob] = time;
        if(bob == 0) return true;
        for(auto x : adj[bob]) {
            bool a = fun1(adj, x, time + 1, m, s);
            if(a) return a;
        }
        m.erase(bob);
        return false;
    }
    void fun2(vector<vector<int>>& adj, int alice, int time, unordered_map<int, int>& m, unordered_set<int>& s, vector<int>& amount, int ans, int& mx) {
        if(s.find(alice) != s.end()) {
            return;
        }
        s.insert(alice);
        if(m.find(alice) == m.end() || time < m[alice]) ans += amount[alice];
        else if(time == m[alice]) {
            ans += amount[alice] / 2;
        }
        if(adj[alice].size() == 1 && alice != 0) {
            mx = max(mx, ans);
        }
        for(auto x : adj[alice]) {
            fun2(adj, x, time + 1, m, s, amount, ans, mx);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_map<int, int> m;
        unordered_set<int> s;
        m[bob] = 0;
        fun1(adj, bob, 0, m, s);
        int ans = 0;
        unordered_set<int> st;
        int mx = INT_MIN;
        fun2(adj, 0, 0, m, st, amount, ans, mx);
        return mx;
    }
};