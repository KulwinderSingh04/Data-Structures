class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({capacity[i], costs[i]});
        }
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
        map<int, int> mp;
        int mx = 0;
        for(auto x : v) {
            if(x.second < budget) mx = max(mx, x.first);
            mp[-x.first]++;
        }
        mp[-v[0].first]--;
        if(mp[-v[0].first] == 0) mp.erase(-v[0].first);
        int i = 0;
        int j = n - 1;
        int ans=  0;
        while(i < j) {
            if(v[i].second + v[j].second < budget) {
                ans = max(ans, v[i].first + -mp.begin() -> first);
                i++;
                mp[-v[i].first]--;
                if(mp[-v[i].first] == 0) mp.erase(-v[i].first);
                
            } else {
                mp[-v[j].first]--;
                if(mp[-v[j].first] == 0) mp.erase(-v[j].first);
                j--;
            }
        }
        return max(mx, ans);
    }
};