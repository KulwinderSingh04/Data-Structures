class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans = 0;
        int n = basket1.size();
        unordered_map<int, int> m;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            m[basket1[i]]++;
            mn = min(mn, basket1[i]);
        }
        for(int i = 0; i < n; i++) {
            m[basket2[i]]--;
            mn = min(mn, basket2[i]);
        }
        vector<int> v;
        for(auto x : m) {
            if(x.second % 2) return -1;
            for(int i = 0; i < abs(x.second) / 2; i++) v.push_back(x.first);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < (v.size() + 1) / 2; i++) {
            ans += min(v[i], 2 * mn);
        }
        return ans;



    }
};