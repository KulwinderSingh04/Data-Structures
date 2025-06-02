class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long x = 0;
        for(auto it : nums) x ^= it;
        int a = 0;
        int b = 0;
        long long rightmostBit = x & -x;
        for(int i = 0; i < n; i++) {
            if(nums[i] & rightmostBit) a ^= nums[i];
            else b ^= nums[i];
        }
        return {a, b};

    }
};