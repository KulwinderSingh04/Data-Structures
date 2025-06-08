
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> m;
        int ans = 0;
        int n = x.size();
        for(int i = 0; i < n; i++) {
            m[x[i]] = max(m[x[i]], y[i]);
        }
        if(m.size() < 3) return -1;
        else {
            vector<int> v;
            for(auto it : m) {
                // cout << it.first << "->" << it.second << endl;
                v.push_back(it.second);
            }
            sort(v.begin(), v.end());
            ans += v.back();
            v.pop_back();
            ans += v.back();
            v.pop_back();
            ans += v.back();
            v.pop_back();
        }
        return ans;
    }
};