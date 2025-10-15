class Solution {
public:
    void fun(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        int n = nums.size();
        ans.push_back(temp);
        for(int j = i; j < n; j++) {
            temp.push_back(nums[j]);
            fun(j + 1, nums, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0, nums, temp, ans);
        return ans;
    }
};