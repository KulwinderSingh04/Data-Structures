class Solution {
public:
    vector<int> bfsBob(int node, vector<vector<int>>& adj) {
        int n = adj.size();
        queue<int> q;
        q.push(node);
        vector<int> vis(n);
        vector<int> par(n);
        for(int i = 0; i < n; i++) par[i] = i;
        vis[node] = 1;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            // cout << t.back() << " ";
            if(t == 0) break;
            for(auto x : adj[t]) {
                if(vis[x] == 0) {
                    par[x] = t;
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        int newNode = 0;
        vector<int> ans;
        while(newNode != node) {
            ans.push_back(newNode);
            newNode = par[newNode];
        }
        // for(auto x : par) cout << x << " ";
        ans.push_back(node);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    typedef pair<int, pair<int, int>> pp;
    int bfsAlice(vector<vector<int>>& adj, vector<int>& bobRoute, vector<int>& amount) {
        int n = adj.size();
        queue<pp> q;
        q.push({0, {0, amount[0]}});
        vector<int> vis(n);
        vis[0] = 1;
        vector<int> bobVis(n);
        bobVis[bobRoute[0]] = 1;
        int ans = INT_MIN;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int node = t.first;
            int idx = t.second.first;
            int money = t.second.second;
            if(adj[node].size() == 1 && node != 0) ans = max(ans, money);
            for(auto x : adj[node]) {
                if(vis[x] == 0) {
                    if(idx + 1 < bobRoute.size() && bobRoute[idx + 1] == x) {
                        q.push({x, {idx + 1, money + amount[x] / 2}});
                    }
                    else if(bobVis[x] == 1) {
                        q.push({x, {idx + 1, money}});
                    } else {
                        q.push({x, {idx + 1, money + amount[x]}});
                    }
                    if(idx + 1 < bobRoute.size()) bobVis[bobRoute[idx + 1]] = 1;
                    vis[x] = 1;
                }
            }
        }
        return ans;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> bobRoute = bfsBob(bob, adj);
        // for(auto x : bobRoute) cout << x << " ";
        // return 1;
        return bfsAlice(adj, bobRoute, amount);
    }
};