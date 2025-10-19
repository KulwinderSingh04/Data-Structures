class Solution {
public:
    typedef pair<int, int> pp;
    int fun(vector<vector<pp>>& adj, int source, int dest) {
        int n = adj.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, source});
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int dis = t.first;
            int node = t.second;
            for(auto x : adj[node]) {
                if(dist[x.first] > dis + x.second) {
                    dist[x.first] = dis + x.second;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        return dist[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int dest, int target) {
        vector<vector<pp>> adj(n);
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        });
        for(auto x : edges) {
            if(x[2] == -1) break;
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        int d = fun(adj, source, dest);
        if(d < target) return {};
        if(d == target) {
            for(auto& x : edges) if(x[2] == -1) x[2] = 1e9 + 5;
            return edges;
        }
        int idx = -1;
        int t = 0;
        for(int i = 0; i < edges.size(); i++) {
            if(edges[i][2] != -1) continue;
            edges[i][2] = 1;
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            d = fun(adj, source, dest);
            if(d <= target) {
                edges[i][2] += target - d;
                idx = i + 1;
                break;
            }
        }
        cout << idx << " "; 
        if(idx == -1) return {};
        for(int i = idx; i < edges.size(); i++) {
            edges[i][2] = 1e9 + 5;
        }
        return edges;
    }
};