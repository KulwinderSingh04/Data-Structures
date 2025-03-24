class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i, vector<int>& vis) {
        vis[i] = 1;
        for(auto x : adj[i]) {
            if(vis[x] == 0) {
                dfs(adj, x, vis);
            }
        }
    }
    bool intersect(vector<int>& a, vector<int>& b, int& k) {
        set<int> s1(a.begin(), a.end());
        int count = 0;
        for(auto x : b) {
            if(s1.find(x) != s1.end()) {
                count++;
                s1.erase(x);
            }
            if(count >= k) return true;
        }
        return count >= k;
    } 
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n;i++) {
            for(int j = i + 1; j < n; j++) {
                if(intersect(properties[i], properties[j], k)) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                ans++;
                dfs(adj, i, vis);
            }
        }
        return ans;
    }
};