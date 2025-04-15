class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            auto t = lower_bound(v.begin(), v.end(), nums[i]);
            if(t - v.begin() == v.size()) {
                v.push_back(nums[i]);
            }
            else {
                v[t - v.begin()] = nums[i];
            }
        }
        return v.size();
    }
};