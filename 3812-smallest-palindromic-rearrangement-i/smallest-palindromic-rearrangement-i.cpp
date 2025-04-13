class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.end());
        unordered_map<char, int> m;
        for(auto ch : s) m[ch]++;
        char cen = 'A';
        int n = s.size();
        vector<char> v(n);
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(m[s[i]] == 1) {
                v[n / 2] = s[i];
                m[s[i]]--;
            }
            if(m[s[i]] >= 2) {
                v[idx] = v[n - 1 - idx] = s[i];
                m[s[i]]--;
                m[s[i]]--;
                idx++;
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++) ans += v[i];
        return ans;
    }
};