class Solution {
public:
    typedef pair<double, int> pp;
    typedef pair<int, double> pp1;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        priority_queue<pp,vector<pp>, greater<pp>> pq;
        vector<double> dist(n, 1e18);
        for(auto& x : succProb) {
            x = -log(x);
        }
        vector<vector<pp1>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        pq.push({0, start_node});
        dist[start_node] = 0;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            double dis = t.first;
            int node = t.second;
            for(auto x : adj[node]) {
                if(dist[x.first] > x.second + dis) {
                    dist[x.first] = x.second + dis;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        if(dist[end_node] == 1e18) return 0;
        return exp(-dist[end_node]);
    }
};