class Solution {
public:
    typedef pair<long long, long long> pp;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pp>> adj(n);
        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]]. push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]]. push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});
        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1; 
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            long long node = t.second;
            long long wt = t.first;
            for(auto x : adj[node]) {
                // cout << x.first << " " << x.second << endl;
                if(dis[x.first] == 1LL * wt + x.second) {
                    ways[x.first] += ways[node];
                    ways[x.first] %= 1000000007;
                }
                if(dis[x.first] > 1LL * wt + x.second) {
                    ways[x.first] = ways[node];
                    dis[x.first] = wt + x.second;
                    pq.push({dis[x.first], x.first});
                }
            }
        }
        return ways[n - 1] % 1000000007;
    }
};