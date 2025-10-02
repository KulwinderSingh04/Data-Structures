class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                adj[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            if(rightChild[i] != -1) {
                adj[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }
        int count = 0;
        int node = -1;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                node = i;
                count++;
            }
        }
        if(count != 1) return false;
        queue<int> q;
        q.push(node);
        vector<int> vis(n);
        vis[node] = 1;
        int c = 0;
        while(q.size()) {
            auto t = q.front();
            c++;
            q.pop();
            for(auto x : adj[t]) {
                if(vis[x] == 1) return false;
                q.push(x);
                vis[x] = 1;
            }
        }
        return c == n;

    }
};