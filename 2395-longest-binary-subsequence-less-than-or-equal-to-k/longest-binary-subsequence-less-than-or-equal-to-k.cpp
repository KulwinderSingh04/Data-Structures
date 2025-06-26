class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') count++;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                int b = n - 1 - i;
                if(pow(2, b) <= k) {
                    k -= pow(2, b);
                    count++;
                } else break;
            }
        }
        return count;
    }
};