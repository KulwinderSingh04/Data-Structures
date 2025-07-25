class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n);
        for(int i = 1; i < n; i++) {
            int count = 0;
            if(nums[i] % 2 == nums[i - 1] % 2) count++;
            pref[i] = pref[i - 1] + count;
        }
        vector<bool> ans;
        int q = queries.size();
        for(int i = 0; i < q; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            ans.push_back(pref[end] == pref[start]);
        }
        return ans;
    }
};