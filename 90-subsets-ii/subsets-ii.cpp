class Solution {
public:
    void fun(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        int n = nums.size();
        ans.push_back(temp);
        if(i >= n) return;
        for(int j = i; j < n; j++) {
            if(j > i && nums[j] == nums[j - 1]) continue;
            temp.push_back(nums[j]);
            fun(j + 1, nums, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        fun(0, nums, v, ans);
        return ans;
    }
};