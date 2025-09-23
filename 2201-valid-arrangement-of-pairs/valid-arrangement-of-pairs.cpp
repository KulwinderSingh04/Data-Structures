class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, stack<int>& st) {
        while(adj[node].size()) {
            int y = adj[node].back();
            adj[node].pop_back();
            dfs(y, adj, st);
        }
        st.push(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        for(auto pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            indegree[pair[1]]++;
            outdegree[pair[0]]++;
        }
        int start = pairs[0][0];
        // for(auto x : indegree) cout << x.first << "->" << x.second << " ";
        // cout << endl;
        // for(auto x : outdegree) cout << x.first << "->" << x.second << " ";
        
        for(auto x : outdegree) {
            if(x.second - indegree[x.first] == 1) {
                start = x.first;
            }
        }
        // cout << start << " ";
        stack<int> st;
        dfs(start, adj, st);
        vector<vector<int>> ans;
        while(st.size()) {
            auto t = st.top();
            st.pop();
            if(st.size()) {
                ans.push_back({t, st.top()});
            }
        }
        return ans;
    }
};