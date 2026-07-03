class Solution {
public:
    typedef pair<long long, long long> pp;
    bool fun(int mid, vector<vector<pp>>& adj, vector<bool>& online, long long k) {
        int n = online.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        pq.push({0, 0});
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            long long score = t.first;
            long long node = t.second;
            if(score != dist[node]) continue;
            // cout << score << " "  << cost << " " << node << endl;
            for(auto x : adj[node]) {
                if(x.second < mid) continue;
                if(online[x.first] == false) continue;
                if(dist[x.first] > score + x.second) {
                    dist[x.first] = score + x.second;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        return dist[n - 1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int ans = -1;
        vector<int> v;
        int n = online.size();
        unordered_set<int> st;
        vector<vector<pp>> adj(n);
        for(auto x : edges) {
            // if(x[2] < mid) continue;
            if(st.find(x[2]) == st.end()) v.push_back(x[2]);
            st.insert(x[2]);
            adj[x[0]].push_back({x[1], x[2]});
        }
        int lo = 0;
        int hi = v.size() - 1;
        sort(v.begin(), v.end());
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(fun(v[mid], adj, online, k)) {
                ans = v[mid];
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;

    }
};