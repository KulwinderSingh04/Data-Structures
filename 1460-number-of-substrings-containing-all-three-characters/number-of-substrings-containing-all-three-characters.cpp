class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        vector<int> hash(3);
        int ans = 0;
        while(j < n) {
            hash[s[j] - 'a']++;
            while(hash[0] && hash[1] && hash[2]) {
                ans += n - j;
                hash[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};