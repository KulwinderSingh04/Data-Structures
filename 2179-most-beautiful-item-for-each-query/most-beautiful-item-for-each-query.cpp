class Solution {
public:
    int fun(vector<vector<int>>& v, int a) {
        int lo = 0;
        int hi = v.size() - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(v[mid][0] == a) return v[mid][1];
            else if(v[mid][0] < a) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi == -1 ? 0 : v[hi][1];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> mp;
        for(auto x : items) {
            mp[x[0]] = max(mp[x[0]], x[1]);
        }
        vector<vector<int>> v;
        for(auto x : mp) {
            v.push_back({x.first, x.second});
        }
        int mx = 0;
        for(int i = 0; i < v.size(); i++) {
            mx = max(mx, v[i][1]);
            v[i][1] = mx;
        }
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            ans[i] = fun(v, queries[i]);
        }
        return ans;
    }
};