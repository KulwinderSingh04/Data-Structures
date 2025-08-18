class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        unordered_map<char, int> dp;
        int mx = 1;
        for(int i = 0; i < n; i++) {
            // dp[s[i]] = 1;
            int a = 1;
            for(int j = max(0, s[i] - 'a' - k); j <= min(25, s[i] - 'a' + k); j++) {
                char ch = j + 'a';
                if(dp.find(ch) != dp.end()) {
                    a = max(a, dp[ch] + 1);
                }
                // cout << ch << " " << s[i] << " " << a << " ";
            }
            dp[s[i]] = a;
            // cout << endl;
            mx = max(dp[s[i]], mx);
        }
        return mx;
    }
};