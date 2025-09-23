class Solution {
public:
    void dfs(string node, unordered_map<string, vector<string>>& adj, stack<string>& st) {
        while(adj[node].size()) {
            string y = adj[node].back();
            adj[node].pop_back();
            dfs(y, adj, st);
        }
        st.push(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(auto x : tickets) {
            adj[x[0]].push_back(x[1]);
        }
        for(auto& x : adj) {
            sort(x.second.begin(), x.second.end(), greater<string> ());
        }
        string node = "JFK";
        vector<string> ans;
        int t = tickets.size() + 1;
        stack<string> st;
        dfs(node, adj, st);
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};