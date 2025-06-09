class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            vector<int> v(26, 0);
            int mx = 0;
            for(int j = i; j < n; j++) {
                v[s[j] - 97]++;
                if(v[s[j] - 97] > mx) mx = v[s[j] - 97];
                int mn = INT_MAX;
                for(int i = 0; i < 26; i++) {
                    if(v[i] != 0) mn = min(mn, v[i]);
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};