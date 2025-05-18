class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        for(auto x : t) tmap[x]++;
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int pos = -1;
        int n = s.size(), count = 0;
        while(j < n) {
            if(tmap[s[j]] > 0) count++;
            tmap[s[j]]--;
            while(count == t.size()) {
                if(ans > j - i + 1) {
                    ans = j - i + 1;
                    pos = i;
                }
                tmap[s[i]]++;
                if(tmap[s[i]] > 0) count--;
                i++;
            }
            j++;
        }
        return pos == -1 ? "" : s.substr(pos, ans);
    }
};