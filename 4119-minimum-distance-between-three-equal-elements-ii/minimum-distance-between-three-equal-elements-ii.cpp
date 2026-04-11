class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> mp(n + 1);
        // int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto x : mp) {
                // cout << x.size() << " ";
            // cout << x.sizE();
            if(x.size() > 2) {
                vector<int>& v = x;
                for(int i = 0; i < x.size() - 2; i++) {
                    // cout << v[i] << " " << v[i + 1] << " ";
                    // cout<< v[i + 2] << " ";
                    ans = min(ans, abs(v[i] - v[i + 1]) + abs(v[i + 2] - v[i + 1]) + abs(v[i] - v[i + 2]));
                }
            }
        }
        return ans == INT_MAX? -1 : ans;
    }
};