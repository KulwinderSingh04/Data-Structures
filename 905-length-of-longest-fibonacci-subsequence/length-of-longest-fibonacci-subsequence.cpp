class Solution {
public:
    int fun(vector<int>& arr, int j, int k, unordered_map<int, int>& m) {
        if(m.find(arr[k] - arr[j]) == m.end()) return 0;
        if(m[arr[k] - arr[j]] >= j) return 0;
        return 1 + fun(arr, m[arr[k] - arr[j]], j, m);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int mx = 0;
        unordered_map<int, int> m;
        // vector<vector<int>> dp(10e9 + 10, vector<int> (10e9 + 10, -1)); 
        for(int i = 0; i  < n; i++) m[arr[i]] = i;
        for(int k = n - 1; k >= 0; k--) {
            for(int j = k - 1; j > 0; j--) {
                int count = 2 + fun(arr, j, k, m);
                mx = max(mx, count);
            }
        }
        if(mx == 2) return 0;
        return mx;
    }
};