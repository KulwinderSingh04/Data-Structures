class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums) {
            ans += min(x % 3, 3 - x % 3);
        }
        return ans;
    }
};