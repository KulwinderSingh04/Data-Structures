class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        unordered_map<char, int> hash(26);
        int ans = 0;
        while(j < n) {
            hash[s[j]]++;
            while(hash[s[j]] > 1) {
                hash[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};