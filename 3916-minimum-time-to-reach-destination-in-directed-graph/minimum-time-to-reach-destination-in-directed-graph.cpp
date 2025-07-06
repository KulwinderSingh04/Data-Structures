class Solution {
public:
    typedef pair<int, int> pp;
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back({x[1], x[2], x[3]});
        }
        vector<int> dis(n, INT_MAX);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            int time = t.first;
            int node = t.second;
            if(node == n - 1) return time;
            for(auto x : adj[node]) {
                int newNode = x[0];
                int ts = x[1];
                int te = x[2];
                int wait = 0;
                if(ts > time) wait += ts - time;
                else if(time > te) continue;
                int newTime = time + wait + 1;
                if(dis[newNode] > newTime) {
                    dis[newNode] = newTime;
                    pq.push({newTime, newNode});
                }
            }

        }
    return dis[n - 1] == INT_MAX ? -1 : dis[n - 1];
    }
};