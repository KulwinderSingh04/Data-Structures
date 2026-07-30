class Solution {
public:
    long long ncr(map<int, int>& mp, int k) {
        long long ways = 1;
        int remaining = 0;

        for(auto [c, cnt] : mp)
            remaining += cnt;

        for(auto [c, cnt] : mp) {
            long long comb = 1;

            for(int i = 1; i <= cnt; i++) {
                comb = comb * (remaining - cnt + i) / i;

                if(comb >= k)
                    comb = k;
            }

            ways *= comb;

            if(ways >= k)
                return k;

            remaining -= cnt;
        }

        return ways;
    }
    string fun(string& s, int k) {
        int n = s.size();
        map<int, int> mp;
        string ans = "";
        for(auto x : s) mp[x]++;
        long long totalWays = ncr(mp, k);

        if(totalWays < k) return "";
        for(int i = 0; i < n; i++) {
            for(auto x : mp) {
                mp[x.first]--;
                int ways = ncr(mp, k);
                if(ways >= k) {
                    ans += x.first;
                    if(mp[x.first] == 0) mp.erase(x.first);
                    break;
                } 
                k -= ways;
                mp[x.first]++;
            }
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        string str = s.substr(0, n / 2);
        string ans = fun(str, k);
        if(ans.empty() && !str.empty()) return "";
        int j = ans.size() - 1;
        if(n % 2) ans += s[n / 2];
        while(j >= 0) {
            ans += ans[j--];
        }
        return ans;
    }
};