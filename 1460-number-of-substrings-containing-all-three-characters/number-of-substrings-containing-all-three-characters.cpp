class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char, int> m;
        int n = s.size();
        while(j < n) {
            m[s[j]]++;
            while(m.size() == 3) {
                ans += n - j ;
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};