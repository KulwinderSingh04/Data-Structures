class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int sum = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] == nums[i] - 1) sum += nums[i];
            else break;
        }
        for(int i = sum; i < sum + 50; i++) {
            if(st.find(i) == st.end()) return i;
        }
        return 1;
    }
};