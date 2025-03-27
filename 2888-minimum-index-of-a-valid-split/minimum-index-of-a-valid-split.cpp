class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        nth_element(v.begin(), v.begin() + n / 2, v.end());
        int count = 0;
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == v[n / 2]) count++;
            if(count > (i + 1) / 2 && idx == -1) {
                idx = i;
                // one = count;
            }
        }
        if(count - ((idx + 1) / 2 + 1) >= (n - 1 - idx) / 2 + 1) return idx;
        return -1;
    }
};