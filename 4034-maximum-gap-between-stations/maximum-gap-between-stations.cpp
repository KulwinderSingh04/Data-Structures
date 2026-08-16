class Solution {
public:
    typedef pair<int, int> pp;
    int maximumGap(string skill, string station) {
        vector<int> end(26, -1);
        for(int i = 0; i < station.size(); i++) {
            end[station[i] - 'a'] = i;
        }
        int cnt = 0;
        unordered_map<char, unordered_set<int>> mp;
        int n = skill.size();
        for(int i = 0; i < n - 1; i++) {
            mp[skill[i]].insert(i);
        }
        vector<int> pref(station.size()), suff(station.size());
        int j = 0;
        for(int i = 0; i < station.size(); i++) {
            if(j < skill.size() && skill[j] == station[i]) {
                j++;
            }
            pref[i] = j;
        }
        j = n - 1;
        for(int i = station.size() - 1; i >= 0; i--) {
            if(j < skill.size() && skill[j] == station[i]) {
                j--;
            }
            suff[i] = -(n - j - 1);
        }
        j = 0;
        int ans = 0;
        for(int i = 0; i < station.size(); i++) {
            if(j < skill.size() - 1 && station[i] == skill[j]) {
                int x = n - pref[i];
                int idx = upper_bound(suff.begin(), suff.end(), -x) - suff.begin() - 1;
                if(idx != -1) {
                    ans = max(ans, idx - i);
                }
                j++;
            }
        }
        return ans;
    }
};