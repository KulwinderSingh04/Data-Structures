class Solution {
public:
    bool isMatch(string a, string b) {
        if(a.size() != b.size()) return false;
        // cout << a << " " << b << endl;
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if(a[i] == '*') continue;
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    long long fun(int i, string& source, string& target, vector<vector<string>>& rules, vector<int>& cost, vector<long long>& dp) {
        int n = source.size();
        if(i == n) return 0;
        long long ans = 1e18;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < n; j++) {
            if(source.substr(i, j - i + 1) == target.substr(i, j - i + 1)) {
                ans = min(ans, fun(j + 1, source, target, rules, cost, dp));
            } else break;
        }
        for(int j = 0; j < rules.size(); j++) {
            // cout << rules[j][0] << endl;
            // cout << isMatch(rules[j][0], source.substr(i, rules[j][0].size())) << endl;
            if(isMatch(rules[j][0], source.substr(i, rules[j][0].size())) && isMatch(rules[j][1], target.substr(i, rules[j][1].size()))) {
                int stars = 0;
                for(auto x : rules[j][0]) stars += (x == '*');
                ans = min(ans, cost[j] + stars + fun(i + rules[j][0].size(), source, target, rules, cost, dp));
            }
        }
        return dp[i] = ans;
    }
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size();
        if(source == target) return 0;
        vector<long long> dp(n, -1);
        long long t = fun(0, source, target, rules, costs, dp);
        return t > 1e10 ? -1 : t;
    }
};