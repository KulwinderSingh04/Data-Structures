class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        vector<int> m(3);
        while(j < n) {
            m[s[j] - 'a']++;
            while(m[0] > 0 && m[1] > 0 && m[2] > 0) {
                ans += n - j;
                m[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};