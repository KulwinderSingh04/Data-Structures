class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        unordered_map<int, set<int>> mp;
        int j = 0;
        int ans = 0;
        while(j < n) {
            int idx = i - 1;
            for(int k = j - 1; k > max(0, idx); k--) {
                if(mp.find(nums[j] + nums[k]) != mp.end()) {
                    int id = -*(mp[nums[j] + nums[k]].begin());
                    if(id < k) idx = max(idx, id);
                    else idx = max(idx, k);
                }
            }
            for(int k = j - 1; k > max(0, idx); k--) {
                if(mp.find(abs(nums[j] - nums[k])) != mp.end()) {
                    if(abs(nums[j] - nums[k]) == nums[k]) {
                        if(mp[nums[k]].size() > 1) {
                            auto itr = next(mp[nums[k]].begin());
                            idx = max(idx, -*itr);
                        }
                    }
                    else {
                        int id = -*(mp[abs(nums[j] - nums[k])].begin());
                        if(id < k) idx = max(idx, id);
                        else idx = max(idx, k);
                    }
                }
            }
            // cout << idx << endl;
            i = idx + 1;
            for(int k = i; k <= idx; k++) {
                mp[nums[k]].erase(-k);
                if(mp[nums[k]].size() == 0) mp.erase(nums[k]);
            }
            ans = max(ans, j - idx);
            mp[nums[j]].insert(-j);
            j++;
        }
        return ans;
    }
};