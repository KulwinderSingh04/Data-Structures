class Solution {
public:
    typedef pair<int, int> pp;
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pp> v;
        int n = rocks.size();
        for(int i= 0; i < n; i++) {
            v.push_back({capacity[i], rocks[i]});
        }
        sort(v.begin(), v.end(), [&](pp& a, pp& b) {
            return (a.first - a.second) < (b.first - b.second); 
        });
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int t = v[i].first - v[i].second;
            if(additionalRocks - t >= 0) {
                ans++;
                additionalRocks -= t;
            } else return ans;
        }
        return ans;
    }
};