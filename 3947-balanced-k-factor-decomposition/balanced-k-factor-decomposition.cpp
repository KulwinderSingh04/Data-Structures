class Solution {
public:
    void dfs(int i, long long prod, int k, int target, vector<int>& v, vector<int>& a, vector<int>& ans) {
        int n = v.size();
        if(a.size() > k) return;
        if(i == n) {
            if(prod == target && a.size() == k) {
                if(ans.size() == 0 || ans.back() - ans[0] > a.back() - a[0]) ans = a;
            }
            return;
        }
        if(1LL * v[i] * prod <= target) {
            a.push_back(v[i]);
            dfs(i, prod * v[i], k, target, v, a, ans);
            a.pop_back();
        }

        dfs(i + 1, prod, k, target, v, a, ans);
    }
    vector<int> minDifference(int n, int k) {
        vector<int> v;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) v.push_back(i);
        }
        vector<int> ans;
        vector<int> a;
        dfs(0, 1, k, n, v, a, ans);
        return ans;
    }
};