class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        for(auto x : words) {
            mp[x]++;
        }
        bool flag = true;
        for(auto x : mp) {
            // cout << x.first << " " << x.second << endl;
            auto t = x;
            if(t.first[0] == t.first[1]) {
                ans += t.second / 2 * 4;
                if(t.second % 2  && flag) {
                    ans += 2;
                    flag = false;
                }
            }
            else {
                string a = x.first;
                // cout << a << " ";
                swap(a[0], a[1]);
                if(mp.find(a) != mp.end()) {
                    // cout << x.second << " " << mp[a] << endl;
                    ans += min(x.second, mp[a]) * 2;
                    // cout << ans << " ";
                }
            }
        }
        return ans;
    }
};