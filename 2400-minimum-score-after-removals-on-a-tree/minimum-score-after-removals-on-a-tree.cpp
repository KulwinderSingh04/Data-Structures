class Solution {
public:
    void funXor(int node, int par, vector<vector<int>>& adj, vector<int>& nums, vector<int>& treeXor) {
        treeXor[node] = nums[node];
        for(auto x : adj[node]) {
            if(x == par) continue;
            funXor(x, node, adj, nums, treeXor);
            treeXor[node] ^= treeXor[x];
        }
    }
    void funTime(int node, int par, int& time, vector<vector<int>>& adj, vector<int>& inTime, vector<int>& outTime) {
        inTime[node] = time;
        time++;
        for(auto x : adj[node]) {
            if(x == par) continue;
            funTime(x, node, time, adj, inTime, outTime);
        }
        outTime[node] = time;
        time++;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> xorTree(n);
        funXor(0, -1, adj, nums, xorTree);
        vector<int> inTime(n), outTime(n);
        int time = 0;
        funTime(0, -1, time, adj, inTime, outTime);
        int tot = 0;
        for(auto x : nums) tot ^= x;
        int res = INT_MAX;
        for(int node1 =  1; node1 < n; node1++) {
            for(int node2 = node1 + 1; node2 < n; node2++) {
                if(inTime[node1] < inTime[node2] && outTime[node1] > outTime[node2]) {
                    int xor2 = xorTree[node2];
                    int xor1 = xorTree[node1] ^ xor2;
                    int xor3 = tot ^ xor1 ^ xor2;
                    res = min(res, max(max(xor1, xor2), xor3) - min(min(xor1, xor2), xor3));
                } else if(inTime[node2] < inTime[node1] && outTime[node2] > outTime[node1]) {
                    int xor1 = xorTree[node1];
                    int xor2 = xorTree[node2] ^ xor1;
                    int xor3 = tot ^ xor1 ^ xor2;
                    res = min(res, max(max(xor1, xor2), xor3) - min(min(xor1, xor2), xor3));
                } else {
                    int xor1 = xorTree[node1];
                    int xor2 = xorTree[node2];
                    int xor3 = tot ^ xor1 ^ xor2;
                    res = min(res, max(max(xor1, xor2), xor3) - min(min(xor1, xor2), xor3));
                }
            }
        }
        return res;
    }
};