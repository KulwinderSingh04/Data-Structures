class Solution {
public:
    bool fun(vector<int>& nums, vector<int>& odd, int par) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == par) {
                if(odd[0] >= nums[i]) return false;
            }
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> odd, even;
        sort(nums1.begin(), nums1.end());
        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2) odd.push_back(nums1[i]);
            else even.push_back(nums1[i]);
        }
        if(odd.size() == 0 || even.size() == 0) return true;
        bool a = fun(nums1, odd, 0);
        bool b = fun(nums1, odd, 1);
        return a || b;
    }
};