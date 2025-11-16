class Solution {
public:
    int MOD = 1e9+7;
    int numSub(string s) {
        int n = s.size();
        int i = 0;
        long long ans = 0;
        while(i < n) {
            while(i < n && s[i] != '1') i++;
            if(i == n) return ans;
            int j = i;
            while(j < n && s[j] == '1') j++;
            long long a = j - i;
            ans += (a * (a + 1)) / 2;
            ans %= MOD;
            i = j + 1;
        }
        return ans;
    }
};