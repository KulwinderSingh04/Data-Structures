class Solution {
public:
    int MOD = 1e9 + 7;
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long val = 0;
        vector<bool> ans;
        for(auto x : nums) {
            val *= 2LL;
            val += x;
            val %= 5;
            ans.push_back(val == 0);
        }
        return ans;
    }
};