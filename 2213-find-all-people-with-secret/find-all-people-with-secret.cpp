class Solution {
public:
    typedef pair<int, int> pp;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pp>> adj(n);
        for(auto x : meetings) {
            if(x[0] == firstPerson && x[1] == 0) continue;
            if(x[1] == firstPerson && x[0] == 0) continue;
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        vector<int> ans;
        unordered_set<int> st;
        // ans.push_back(0);
        // ans.push_back(firstPerson);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        while(pq.size()) {
            auto [time, node] = pq.top();
            pq.pop();
            // cout << node << " ";
            st.insert(node);
            while(adj[node].size()) {
                if(adj[node].back().second >= time) {
                    pq.push({adj[node].back().second, adj[node].back().first});
                }
                adj[node].pop_back();
            }
        }
        for(auto x : st) {
            ans.push_back(x);
        }
        return ans;
    }
};