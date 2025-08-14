class Solution {
public:
    int fun(int i, int k, string& s, unordered_map<string, int>& dp) {
        if(k < 0) return 1e4;
        int n = s.size();
        if(i == n || n - i <= k) return 0;
        string str = to_string(i) + '_' + to_string(k);
        if(dp.find(str) != dp.end()) return dp[str];
        int del_i = fun(i + 1, k - 1, s, dp);
        int keep_i = 1e4;
        int deleted = 0;
        int freq = 0;
        int add = 0;
        for(int j = i; j < n && deleted <= k; j++) {
            if(s[j] == s[i]) {
                freq++;
                if(freq == 2 || freq == 10 || freq == 100) {
                    add++;
                }
            } else {
                deleted++;
            }

            keep_i = min(keep_i, 1 + add + fun(j + 1, k - deleted, s, dp));
        }
        return dp[str] = min(keep_i, del_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        unordered_map<string, int> dp;
        return fun(0, k, s, dp);
    }
};