
class Solution {
public:
    typedef pair<int, string> pp;
    long long fun(int i, int j, vector<int>& robot, vector<int>& factory, vector<vector<long long>>& dp) {
        int n = robot.size();
        if(i == n) return 0;
        if(j == factory.size()) return 1e15;
        if(dp[i][j] != -1) return dp[i][j];
        long long pick = 1e15;
        pick = abs(factory[j] - robot[i]) + fun(i + 1, j + 1, robot, factory, dp);
        long long np = fun(i, j + 1, robot, factory, dp);
        return dp[i][j] = min(pick, np);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> v;
        for(auto x : factory) {
            for(int i = 0; i < x[1]; i++) v.push_back(x[0]);
        }
        vector<vector<long long>> dp(robot.size(), vector<long long> (v.size(), -1));
        return fun(0, 0, robot, v, dp);
    }
};