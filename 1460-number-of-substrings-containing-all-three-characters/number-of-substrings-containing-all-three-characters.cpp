class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        vector<int> m(3);
        int n = s.size();
        while(j < n) {
            m[s[j] - 97]++;
            while(m[0] > 0 && m[1] > 0 && m[2] > 0) {
                ans += n - j;
                m[s[i] - 97]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};