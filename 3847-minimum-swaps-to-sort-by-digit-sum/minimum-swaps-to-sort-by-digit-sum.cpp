class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        if(vis[node] == 1) return 0;
        vis[node] = 1;
        return 1 + dfs(adj[node][0], adj, vis);
    }
    int minSwaps(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end(), [](int a, int b) {
            int s1 = 0, s2 = 0;
            int aa = a;
            int bb = b;
            while(a) {
                s1 += a % 10;
                a/= 10;
            }
            while(b) {
                s2 += b % 10;
                b/= 10;
            }
            if(s1 == s2) return aa < bb;
            return s1 < s2;
        });
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[v[i]] = i;
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            adj[i].push_back(mp[nums[i]]);
        }
        int ans = 0;
        vector<int> vis(n);
        for(int i = 0; i < n; i++) if(vis[i] == 0) ans += dfs(i, adj, vis) - 1;
        return ans;
    }
};