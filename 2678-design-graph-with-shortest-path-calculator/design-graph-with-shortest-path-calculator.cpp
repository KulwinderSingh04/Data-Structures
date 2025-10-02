class Graph {
public:
    typedef pair<int, int> pp;
    vector<vector<int>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n, vector<int> (n, INT_MAX));
        for(int i = 0; i < n; i++) adj[i][i] = 0;
        for(auto x : edges) {
            adj[x[0]][x[1]] = x[2];
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if( adj[i][k] != INT_MAX && adj[k][j] != INT_MAX && adj[i][j] > adj[i][k] + adj[k][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }
    
    void addEdge(vector<int> x) {
        int n = adj.size();
        if(adj[x[0]][x[1]] > x[2]) {
            adj[x[0]][x[1]] = x[2];
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(adj[i][x[0]] != INT_MAX && adj[x[1]][j] != INT_MAX && adj[i][j] > adj[i][x[0]] + x[2] + adj[x[1]][j]) {
                        adj[i][j] = adj[i][x[0]] + x[2] + adj[x[1]][j];
                    }
                }
            }
        }

    }
    
    int shortestPath(int node1, int node2) {
        return adj[node1][node2] == INT_MAX ? -1 : adj[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */