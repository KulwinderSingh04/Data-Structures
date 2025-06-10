class Solution {
public:
    int maxDifference(string s) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        int n = s.size();
        vector<int> hash(26);
        for(int i = 0; i < n; i++) {
            hash[s[i] - 97]++;
        }
        for(int i = 0; i < 26; i++) {
            if(hash[i] == 0) continue;
            if(hash[i] % 2 == 0) {
                mn = min(mn, hash[i]);
            } else {
                mx = max(mx, hash[i]);
            }
        }
        // cout << mx << " " << mn << endl;
        return mx - mn;

    }
};