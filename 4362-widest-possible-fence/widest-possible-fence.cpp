class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        unordered_map<int, int> mp, mp2;
        for(auto x : planks) {
            mp[x]++;
            mp2[x]++;
        }
        vector<int> v;
        for(auto x : mp2) {
            v.push_back(x.first);
        }
        // sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            mp[2 * v[i]] += mp2[v[i]] / 2;
            for(int j = i + 1; j < v.size(); j++) {
                mp[v[i] + v[j]] += min(mp2[v[i]], mp2[v[j]]);
            }
        }
        int ans = 0;
        for(auto x : mp) ans = max(x.second, ans);
        return ans;
    }
};