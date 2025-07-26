class Solution {
public:
    int fun(int i, int prev, vector<int>& arr1, vector<int>& arr2, unordered_map<string, int>& dp) {
        int n = arr1.size();
        if(i == n) return 0;
        string str = to_string(i) + '_' + to_string(prev);
        if(dp.find(str) != dp.end()) return dp[str];
        int p = 1e7;
        if(arr1[i] > prev) p = fun(i + 1, arr1[i], arr1, arr2, dp);

        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        int np = 1e7;
        if(idx != arr2.size()) np = 1 + fun(i + 1, arr2[idx], arr1, arr2, dp);
        return dp[str] = min(np, p);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        unordered_map<string, int> dp;
        int t = fun(0, -1, arr1, arr2, dp);
        return t == 1e7 ? -1 : t;
    }
};