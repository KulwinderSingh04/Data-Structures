class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int mxFreq = 0;
        vector<int> m(26);
        int ans = 0;
        while(j < n) {
            m[s[j] - 65]++;
            mxFreq = max(mxFreq, m[s[j] - 65]);
            int len = j - i + 1;
            while(len - mxFreq > k) {
                m[s[i] - 65]--;
                mxFreq = 0;
                for(int t = 0; t < 26; t++) {
                    mxFreq = max(mxFreq, m[t]);
                }
                i++;
                len = j - i + 1;
            }
            ans = max(ans, len);
            j++;
        }
        return ans;
    }
};