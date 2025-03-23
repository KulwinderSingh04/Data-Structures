class Solution {
public:
    typedef pair<int, int> pp;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pp>> adj(n + 1);
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]]. push_back({times[i][1], times[i][2]});
        }
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, k});
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int node = t.second;
            int wt = t.first;
            for(auto x : adj[node]) {
                if(dis[x.first] > wt + x.second) {
                    dis[x.first] = wt + x.second;
                    pq.push({dis[x.first], x.first});
                }
            }
        }
        int mx = 0;
        for(int i = 1; i < n + 1; i++) mx = max(mx, dis[i]);
        return mx == INT_MAX ? -1 : mx;
    }
};