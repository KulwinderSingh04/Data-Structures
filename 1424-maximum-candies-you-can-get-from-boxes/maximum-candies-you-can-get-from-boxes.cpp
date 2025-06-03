class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        unordered_set<int> closedBoxes;
        
        vector<int> vis(n);
        for(auto x : initialBoxes) {
            if(status[x] == 1) {
                q.push(x);
                vis[x] = 1;
            }
            else closedBoxes.insert(x);
        }
        // unordered_map<int, int> m;
        int ans = 0;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            ans += candies[t];
            for(auto x : keys[t]) {
                status[x] = 1;
            }
            for(auto x : containedBoxes[t]) {
                if(vis[x] == 1) continue;
                if(status[x] == 1) {
                    q.push(x);
                    vis[x] = 1;
                }
                else closedBoxes.insert(x);
            }
            // vector<int> v;
            for(auto x : closedBoxes) {
                if(vis[x] == 1) continue;
                if(status[x] == 1) {
                    q.push(x);
                    vis[x] = 1;
                }
            }
            // for(auto x : v) closedBoxe
        }
        return ans;
    }
};