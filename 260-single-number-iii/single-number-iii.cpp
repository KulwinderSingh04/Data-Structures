class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long num = 0;
        int n = nums.size();
        for(auto x : nums) num ^= x;
        long long rightmostBit = (num & num - 1) ^ num;
        int b1 = 0, b2 = 0;
        for(int i = 0; i < n; i++) {
            if((rightmostBit & nums[i]) == 0) b1 ^= nums[i];
            else b2 ^= nums[i];
        }
        return {b1, b2};
    }
};