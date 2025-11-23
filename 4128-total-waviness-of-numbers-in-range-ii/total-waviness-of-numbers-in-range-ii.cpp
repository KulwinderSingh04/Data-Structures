class Solution {
public:
    long long fun(int i, int tight, int flag, int prev1, int prev2, int count, string& str, vector<vector<vector<vector<vector<vector<long long>>>>>>& dp) {
        if(i == str.size()) return count;
        if(dp[i][tight][flag][prev1][prev2][count] != -1) return dp[i][tight][flag][prev1][prev2][count];
        int limit = (tight == 1 ? str[i] - '0' : 9);
        long long ans = 0;
        for(int j = 0; j <= limit; j++) {
            if(flag != 2) {
                if(flag == 0) {
                    if(j == 0) {
                        ans += fun(i + 1, (tight && (str[i] - '0' == j)), 0, 10, prev1, count, str, dp);
                    } else {
                        ans += fun(i + 1, (tight && (str[i] - '0' == j)), 1, j, prev1, count, str, dp);
                    }
                } else {
                    ans += fun(i + 1, (tight && (str[i] - '0' == j)), 2, j, prev1, count, str, dp);
                }
            } else {
                // two valid digits are present minimum
                int a = 0;
                if(prev2 > prev1 && j > prev1) {
                    a++;
                }
                if(prev2 < prev1 && j < prev1) {
                    a++;
                }
                ans += fun(i + 1, (tight && (str[i] - '0' == j)), flag, j, prev1, count + a, str, dp);
            }
        }  
        return dp[i][tight][flag][prev1][prev2][count] = ans; 
    }

    long long totalWaviness(long long num1, long long num2) {
        if(num2 < 100) return 0;
        long long wavi = 0;
        string str = to_string(num1);
        for(int i = 1; i < str.size() - 1; i++) {
            if((str[i] > str[i - 1] && str[i] > str[i + 1]) || (str[i] < str[i - 1] && str[i] < str[i + 1])) wavi++;
        }
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        vector<vector<vector<vector<vector<vector<long long>>>>>> dp1(s1.size(), vector<vector<vector<vector<vector<long long>>>>> (2, vector<vector<vector<vector<long long>>>> (3, vector<vector<vector<long long>>> (11, vector<vector<long long>> (11, vector<long long> (15, -1))))));
        vector<vector<vector<vector<vector<vector<long long>>>>>> dp2(s2.size(), vector<vector<vector<vector<vector<long long>>>>> (2, vector<vector<vector<vector<long long>>>> (3, vector<vector<vector<long long>>> (11, vector<vector<long long>> (11, vector<long long> (15, -1))))));
        // long long a = fun(0, 1, 0, 0, 0, s2, dp2);
        // long long b = fun(0, 1, 0, 0, 0, s1, dp2);
        return wavi + fun(0, 1, 0, 10, 10, 0, s2, dp2) - fun(0, 1, 0, 10, 10, 0, s1, dp1);
    }
};