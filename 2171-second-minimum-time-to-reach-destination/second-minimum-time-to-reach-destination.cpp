class Solution {
public:
    typedef pair<int, int> pp;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<pp> pq;
        pq.push({0, 1});
        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        dist1[1] = 0;
        while(pq.size()) {
            auto t = pq.front();
            pq.pop();
            int dis = t.first;
            int node = t.second;
            int wait = 0;
            if((dis / change) % 2) wait = change - (dis % change);
            for(auto x : adj[node]) {
                if(dist1[x] > dis + time + wait) {
                    dist2[x] = dist1[x];
                    dist1[x] = dis + time + wait;
                    pq.push({dist1[x], x});
                } else if(dist2[x] > dis + time + wait && dist1[x] != dis + time + wait) {
                    dist2[x] = dis + time + wait;
                    pq.push({dist2[x], x});
                }
            }
        }
        return dist2[n];
    }
};