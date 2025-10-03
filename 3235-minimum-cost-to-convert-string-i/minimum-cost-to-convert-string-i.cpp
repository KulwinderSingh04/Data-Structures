class Solution {
public:
    typedef pair<char, long long> pp1;
    typedef pair<long long, char> pp2;
    long long bfs(char src, char tar, unordered_map<char, vector<pp1>>& adj) {
        vector<long long> dist(26, LLONG_MAX);
        priority_queue<pp2, vector<pp2>, greater<pp2>> pq;
        pq.push({0, src});
        dist[src - 97] = 0;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            for(auto x : adj[t.second]) {
                if(dist[x.first - 97] > t.first + x.second) {
                    dist[x.first - 97] = t.first + x.second;
                    pq.push({dist[x.first - 97], x.first});
                }
            }
        }
        if(dist[tar - 97] == LLONG_MAX) return -1;
        return dist[tar - 97];

    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pp1>> adj;
        for(int i = 0; i < changed.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }
        long long ans = 0;
        map<pair<char, char>, long long> mp;
        for(int i = 0; i < source.size(); i++) {
            if(source[i] == target[i]) continue;
            if(mp.find({source[i], target[i]}) != mp.end()) {
                ans += mp[{source[i], target[i]}];
                continue;
            }
            long long t = bfs(source[i], target[i], adj);
            if(t == -1) return t;
            mp[{source[i], target[i]}] = t;
            ans += t;
        }
        return ans;
    }
};