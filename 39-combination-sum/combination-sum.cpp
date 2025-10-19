class Solution {
public:
    void fun(int i, int target, vector<int>& temp, vector<int>& cand, vector<vector<int>>& ans) {
        int n = cand.size();
        if(i == n) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if(target < 0) return;

        temp.push_back(cand[i]);
        fun(i , target - cand[i], temp, cand, ans);
        temp.pop_back();

        fun(i + 1, target, temp, cand, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0, target, temp, candidates, ans);
        return ans;
    }
};