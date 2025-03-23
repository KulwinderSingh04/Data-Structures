class Solution {
public:
    typedef pair<int, int> pp;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pp>> adj(n);
        for(auto x : flights) {
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int> dis(n, INT_MAX);
        queue<pair<int, pp>> pq;
        pq.push({0, {src, 0}});
        dis[src] = 0;
        while(pq.size()) {
            auto t = pq.front();
            pq.pop();
            int stop = t.second.second;
            int node = t.second.first;
            int wt = t.first;
            if(stop > k) continue;
            for(auto x : adj[node]) {
                if(wt + x.second < dis[x.first]) {
                    dis[x.first] = wt + x.second;
                    pq.push({dis[x.first], {x.first, stop + 1}});
                }
            }
        }
        if(dis[dst] == INT_MAX) return -1;
        return dis[dst];
    }
};