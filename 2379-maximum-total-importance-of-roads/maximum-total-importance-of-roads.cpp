class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        for(auto x : roads) {
            degree[x[0]]++;
            degree[x[1]]++;
        }
        sort(degree.begin(), degree.end(), greater<int> ());
        int t = n;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += 1LL * t * degree[i];
            t--;
        }
        return ans;
    }
};