class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(17, vector<int> (n));
        dp[0] = parent;
        for(int i = 1; i < 17; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i - 1][j] == -1) dp[i][j] = -1;
                else dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 17; i++) {
            if((1 << i) & k) {
                node = dp[i][node];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */