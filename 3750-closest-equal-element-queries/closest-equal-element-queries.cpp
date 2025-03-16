class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& q) {
        vector<int> v(nums.begin(), nums.end());
        int n = nums.size();
        v.insert(v.end(), nums.begin(), nums.end());
        vector<int> res(n, INT_MAX);
        unordered_map<int, int> m;
        for(int i = 0; i < v.size(); i++) {
            if(m.find(v[i]) != m.end()) {
                res[i % n] = min(res[i % n], abs(i - m[v[i]]));
                res[m[v[i]] % n] = min(res[m[v[i]] % n], abs(i - m[v[i]]));
            }
            m[v[i]] = i;
        }
        vector<int> ans;
        for(int i = 0; i < q.size(); i++) {
            ans.push_back(res[q[i]]);
            if(ans.back() == n) ans.back() = -1;
            if(ans.back() > n / 2) ans.back() = n - ans.back();
        }
        return ans;
    }
};