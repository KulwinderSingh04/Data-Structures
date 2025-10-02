class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            for(auto x : routes[i]) {
                mp[x].push_back(i);
            }
        }
        vector<vector<int>> adj(n);
        for(auto x : mp) {
            for(int i = 0; i < x.second.size(); i++) {
                for(int j = i + 1; j < x.second.size(); j++) {
                    adj[x.second[i]].push_back(x.second[j]);
                    adj[x.second[j]].push_back(x.second[i]);
                }
            }
        }
        queue<pair<int, int>> q;
        vector<int> vis(n);
        int ans = INT_MAX;
        for(auto x : mp[source]) {
            q.push({x, 1});
            vis[x] = 1;
        }
        unordered_set<int> tar;
        for(auto x : mp[target]) tar.insert(x);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(tar.find(t.first) != tar.end()) ans = min(ans, t.second);
            for(auto x : adj[t.first]) {
                if(vis[x] == 0) {
                    q.push({x, t.second + 1});
                    vis[x] = 1;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};