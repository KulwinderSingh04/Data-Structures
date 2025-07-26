class Solution {
public:
    int fun(vector<int>& nums, vector<bool>& visited, int op, unordered_map<vector<bool>, int>& dp) {
        int mx = 0;
        int n = nums.size();
        if(dp.find(visited) != dp.end()) return dp[visited];
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            for(int j = i + 1; j < n; j++) {
                if(visited[j]) continue;
                visited[i] = true;
                visited[j] = true;
                int s = op * __gcd(nums[i], nums[j]);
                int rem = fun(nums, visited, op + 1, dp);
                visited[i] = false;
                visited[j] = false;
                mx = max(mx, s + rem);
            }
        }
        return dp[visited] = mx;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        unordered_map<vector<bool>, int> dp;
        return fun(nums, visited, 1, dp);
    }
};