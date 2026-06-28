class Solution {
public:
    using T = tuple<long long, int, int>;
    typedef pair<long long, long long> pp;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pp>> adj(n);
        sort(edges.begin(), edges.end());
        int prev0 = -1, prev1 = -1;
        for(auto& x : edges) {
            if(x[0] == prev0 && x[1] == prev1) continue;
            adj[x[0]].push_back({x[1], x[2]});
            prev0 = x[0];
            prev1 = x[1];
        }
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<long long>> dist(n, vector<long long> (power + 1, LLONG_MAX));
        dist[source][power] = 0;
        pq.push({0, power, source});
        while(pq.size()) {
            auto [time,pow,node] = pq.top();
            pq.pop();
            // if(time != dist[node][pow]) continue;
            for(auto x : adj[node]) {
                if(pow >= cost[node] && dist[x.first][pow - cost[node]] > time + x.second) {
                    dist[x.first][pow - cost[node]] = time + x.second;
                    pq.push({dist[x.first][pow - cost[node]], pow - cost[node], x.first});
                }
            }
        }
        vector<long long> ans = {LLONG_MAX, -1};
        for(int i = 0; i < dist[target].size(); i++) {
            if(dist[target][i] < ans[0]) {
                ans = {dist[target][i], i};
            } else if(dist[target][i]==ans[0]){
                ans[1]=max(ans[1], (long long)i);
            }
        }
        if(ans[0] == LLONG_MAX) return {-1, -1};
        return ans;

    }
};