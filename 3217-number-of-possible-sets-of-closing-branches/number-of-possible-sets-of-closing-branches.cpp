class Solution {
public:
    typedef pair<int, int> pp;
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        sort(roads.begin(), roads.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        int ans = 0;
        for(int gph = 0; gph < (1 << n); gph++) {
            vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
            set<pp> st;
            for(auto road : roads) {
                int u = road[0];
                int v = road[1];
                if(st.find({u, v}) != st.end()) continue;
                cout << (gph & (1 << u)) <<" " << (gph & (1 << v)) << endl;
                if((gph & (1 << u)) && (gph & (1 << v))) {
                    dist[u][v] = road[2];
                    dist[v][u] = road[2];
                    st.insert({u, v});
                    st.insert({v, u});
                } 
            }
            for(int i = 0; i < n; i++) dist[i][i] = 0;
            for(int k = 0; k < n; k++) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
            bool flag = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if((gph & (1 << i)) && (gph & (1 << j))) {
                        if(dist[i][j] > maxDistance) {
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
            if(flag) continue;
            ans++;
        }
        return ans;
    }
};