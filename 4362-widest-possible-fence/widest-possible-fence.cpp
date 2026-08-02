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
            for(int j = i; j < v.size(); j++) {
                if(i == j) mp[2 * v[i]] += mp2[v[i]] / 2;
                else mp[v[i] + v[j]] += min(mp2[v[i]], mp2[v[j]]);
            }
        }
        int ans =0;
        for(auto x : mp) ans = max(x.second, ans);
        return ans;
    }
};