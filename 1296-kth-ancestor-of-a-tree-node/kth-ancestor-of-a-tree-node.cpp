class TreeAncestor {
public:
    vector<vector<int>> dp;
    void fun(vector<vector<int>>& dp, vector<int>& par) {
        int n = par.size();
        for(int i = 0; i < n; i++) {
            dp[0][i] = par[i];
        }

        for(int i = 1; i < 17; i++) {
            for(int j = 1; j < n; j++) {
                if(dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(17, vector<int> (n, -1));
        fun(dp, parent);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 16; i >= 0; i--) {
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