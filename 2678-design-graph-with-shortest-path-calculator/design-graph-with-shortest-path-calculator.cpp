class Graph {
public:
    typedef pair<int, int> pp;
    vector<vector<pp>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto x : edges) {
            adj[x[0]].push_back({x[1], x[2]});
        }
    }
    
    void addEdge(vector<int> x) {
        adj[x[0]].push_back({x[1], x[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, node1});
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
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
        if(dist[node2] == INT_MAX) return -1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */