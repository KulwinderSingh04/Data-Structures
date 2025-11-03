class Solution {
public:
    int bfs(int node, vector<vector<int>>& adj,vector<int>& vis) {
        queue<pair<int, int>> q;
        q.push({node, 0});
        vis[node] = 1;
        int ans = 0;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            ans = max(ans, t.second);
            for(auto x : adj[t.first]) {
                if(vis[x] == 0) {
                    q.push({x, t.second + 1});
                    vis[x] = 1;
                }
            }
        }
        return ans;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            adj[favorite[i]].push_back(i);
        }
        int largestCycle = 0;
        int happyCouple = 0;
        vector<int> vis(n);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                unordered_map<int, int> mp;
                int currNode = i;
                int nodeCount = 0;
                while(vis[currNode] == 0) {
                    vis[currNode] = 1;
                    mp[currNode] = nodeCount;
                    nodeCount++;
                    int nextNode = favorite[currNode];
                    if(mp.find(nextNode) != mp.end()) {
                        int cycleLen = nodeCount - mp[nextNode];
                        largestCycle = max(largestCycle, cycleLen);
                        if(cycleLen == 2) {
                            vector<int> visited(n);
                            visited[nextNode] = 1;
                            happyCouple += 2 + bfs(currNode, adj, visited) + bfs(nextNode, adj, visited);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }
        return max(happyCouple, largestCycle);
    }
};