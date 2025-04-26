class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int n = s.size();
        for(auto x : t) m[x]++;
        int i = 0;
        int j = 0;
        int count = 0, sIdx = -1;
        int ans = INT_MAX;
        while(j < n) {
            if(m[s[j]] > 0) count++;
            m[s[j]]--;
            while(count == t.size()) {
                if(ans > j - i + 1) {
                    ans = j - i + 1;
                    sIdx = i;
                }
                m[s[i]]++;
                if(m[s[i]] > 0) count--; 
                i++;
            }
            j++;
        }
        return sIdx == -1 ? "" : s.substr(sIdx, ans);
    }
};